#include "PmergeMe.hpp"

/* ===================== Orthodox Canonical Form ===================== */

PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vec(other._vec), _deq(other._deq), _unsorted(other._unsorted),
	  _vecTime(other._vecTime), _deqTime(other._deqTime) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
		_unsorted = other._unsorted;
		_vecTime = other._vecTime;
		_deqTime = other._deqTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

/* ===================== Parsing ===================== */

void PmergeMe::parseArgs(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if (arg.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < arg.size(); j++)
		{
			if (!std::isdigit(arg[j]))
				throw std::runtime_error("Error");
		}
		long num = std::atol(arg.c_str());
		if (num <= 0 || num > INT_MAX)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
		_unsorted.push_back(static_cast<int>(num));
	}
}

/* ===================== Jacobsthal Numbers ===================== */

static size_t jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	size_t prev2 = 0;
	size_t prev1 = 1;
	size_t curr = 0;
	for (size_t i = 2; i <= n; i++)
	{
		curr = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return curr;
}

std::vector<size_t> PmergeMe::generateJacobInsertionOrder(size_t n)
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	// Generate Jacobsthal numbers up to n
	std::vector<size_t> jacobNums;
	size_t k = 1;
	while (jacobsthal(k) < n)
	{
		jacobNums.push_back(jacobsthal(k));
		k++;
	}
	jacobNums.push_back(n); // sentinel

	// Build insertion order using Jacobsthal sequence
	// We iterate between consecutive Jacobsthal numbers in reverse
	std::vector<bool> used(n + 1, false);

	for (size_t i = 0; i < jacobNums.size(); i++)
	{
		size_t jac = jacobNums[i];
		if (jac <= n && !used[jac])
		{
			order.push_back(jac);
			used[jac] = true;
		}
		// Fill backwards from jac-1 down to previous Jacobsthal+1
		size_t prevJac = (i > 0) ? jacobNums[i - 1] : 0;
		for (size_t j = jac - 1; j > prevJac; j--)
		{
			if (!used[j])
			{
				order.push_back(j);
				used[j] = true;
			}
		}
	}

	// Add any remaining indices
	for (size_t i = 1; i <= n; i++)
	{
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

std::deque<size_t> PmergeMe::generateJacobInsertionOrderDeque(size_t n)
{
	std::deque<size_t> order;
	if (n == 0)
		return order;

	std::vector<size_t> jacobNums;
	size_t k = 1;
	while (jacobsthal(k) < n)
	{
		jacobNums.push_back(jacobsthal(k));
		k++;
	}
	jacobNums.push_back(n);

	std::vector<bool> used(n + 1, false);

	for (size_t i = 0; i < jacobNums.size(); i++)
	{
		size_t jac = jacobNums[i];
		if (jac <= n && !used[jac])
		{
			order.push_back(jac);
			used[jac] = true;
		}
		size_t prevJac = (i > 0) ? jacobNums[i - 1] : 0;
		for (size_t j = jac - 1; j > prevJac; j--)
		{
			if (!used[j])
			{
				order.push_back(j);
				used[j] = true;
			}
		}
	}
	for (size_t i = 1; i <= n; i++)
	{
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

/* ===================== Binary Search Insert ===================== */

std::vector<int>::iterator PmergeMe::binarySearchInsert(
	std::vector<int> &chain, int value, std::vector<int>::iterator end)
{
	std::vector<int>::iterator low = chain.begin();
	std::vector<int>::iterator high = end;

	while (low < high)
	{
		std::vector<int>::iterator mid = low + (high - low) / 2;
		if (*mid < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

std::deque<int>::iterator PmergeMe::binarySearchInsert(
	std::deque<int> &chain, int value, std::deque<int>::iterator end)
{
	std::deque<int>::iterator low = chain.begin();
	std::deque<int>::iterator high = end;

	while (low < high)
	{
		std::deque<int>::iterator mid = low + (high - low) / 2;
		if (*mid < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

/* ============== Ford-Johnson Sort for std::vector ============== */

void PmergeMe::fordJohnsonSort(std::vector<int> &container)
{
	size_t size = container.size();
	if (size <= 1)
		return;

	// Step 1: Group elements into pairs and compare
	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = false;
	int straggler = 0;

	for (size_t i = 0; i + 1 < size; i += 2)
	{
		if (container[i] > container[i + 1])
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
		else
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
	}
	if (size % 2 != 0)
	{
		hasStraggler = true;
		straggler = container[size - 1];
	}

	// Step 2: Extract the larger elements (winners) and recursively sort them
	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].first);

	fordJohnsonSort(winners);

	// Step 3: Build main chain from sorted winners, and pend from their paired losers
	// We need to reorder pairs according to sorted winners order
	std::vector<int> pend;
	std::vector<int> mainChain;

	// Map: after sorting winners, we need to find the corresponding loser for each winner
	// Build a map from winner value to loser value
	// (Note: duplicates are possible per subject: "left to your discretion")
	// We use a vector of pairs to handle duplicates properly
	std::vector<std::pair<int, int> > winnerToLoser;
	for (size_t i = 0; i < pairs.size(); i++)
		winnerToLoser.push_back(pairs[i]);

	for (size_t i = 0; i < winners.size(); i++)
	{
		mainChain.push_back(winners[i]);
		// Find the corresponding loser
		for (size_t j = 0; j < winnerToLoser.size(); j++)
		{
			if (winnerToLoser[j].first == winners[i])
			{
				pend.push_back(winnerToLoser[j].second);
				winnerToLoser.erase(winnerToLoser.begin() + static_cast<long>(j));
				break;
			}
		}
	}

	// Step 4: Insert first pend element at the beginning (it's always <= mainChain[0])
	if (!pend.empty())
	{
		mainChain.insert(mainChain.begin(), pend[0]);
	}

	// Step 5: Insert remaining pend elements using Jacobsthal order with binary search
	if (pend.size() > 1)
	{
		std::vector<size_t> insertOrder = generateJacobInsertionOrder(pend.size() - 1);

		size_t inserted = 1; // we already inserted pend[0]
		for (size_t i = 0; i < insertOrder.size(); i++)
		{
			size_t pendIdx = insertOrder[i]; // 1-based index into remaining pend
			int value = pend[pendIdx];

			// The bound for binary search: the element's partner position + number of previously inserted elements
			size_t bound = pendIdx + inserted;
			if (bound > mainChain.size())
				bound = mainChain.size();

			std::vector<int>::iterator pos = binarySearchInsert(
				mainChain, value, mainChain.begin() + static_cast<long>(bound));
			mainChain.insert(pos, value);
			inserted++;
		}
	}

	// Step 6: Insert straggler if present
	if (hasStraggler)
	{
		std::vector<int>::iterator pos = binarySearchInsert(
			mainChain, straggler, mainChain.end());
		mainChain.insert(pos, straggler);
	}

	container = mainChain;
}

/* ============== Ford-Johnson Sort for std::deque ============== */

void PmergeMe::fordJohnsonSort(std::deque<int> &container)
{
	size_t size = container.size();
	if (size <= 1)
		return;

	// Step 1: Group elements into pairs and compare
	std::deque<std::pair<int, int> > pairs;
	bool hasStraggler = false;
	int straggler = 0;

	for (size_t i = 0; i + 1 < size; i += 2)
	{
		if (container[i] > container[i + 1])
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
		else
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
	}
	if (size % 2 != 0)
	{
		hasStraggler = true;
		straggler = container[size - 1];
	}

	// Step 2: Extract the larger elements (winners) and recursively sort them
	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].first);

	fordJohnsonSort(winners);

	// Step 3: Build main chain from sorted winners, and pend from their paired losers
	std::deque<int> pend;
	std::deque<int> mainChain;

	std::deque<std::pair<int, int> > winnerToLoser;
	for (size_t i = 0; i < pairs.size(); i++)
		winnerToLoser.push_back(pairs[i]);

	for (size_t i = 0; i < winners.size(); i++)
	{
		mainChain.push_back(winners[i]);
		for (size_t j = 0; j < winnerToLoser.size(); j++)
		{
			if (winnerToLoser[j].first == winners[i])
			{
				pend.push_back(winnerToLoser[j].second);
				winnerToLoser.erase(winnerToLoser.begin() + static_cast<long>(j));
				break;
			}
		}
	}

	// Step 4: Insert first pend element at the beginning
	if (!pend.empty())
	{
		mainChain.push_front(pend[0]);
	}

	// Step 5: Insert remaining pend elements using Jacobsthal order
	if (pend.size() > 1)
	{
		std::deque<size_t> insertOrder = generateJacobInsertionOrderDeque(pend.size() - 1);

		size_t inserted = 1;
		for (size_t i = 0; i < insertOrder.size(); i++)
		{
			size_t pendIdx = insertOrder[i];
			int value = pend[pendIdx];

			size_t bound = pendIdx + inserted;
			if (bound > mainChain.size())
				bound = mainChain.size();

			std::deque<int>::iterator pos = binarySearchInsert(
				mainChain, value, mainChain.begin() + static_cast<long>(bound));
			mainChain.insert(pos, value);
			inserted++;
		}
	}

	// Step 6: Insert straggler if present
	if (hasStraggler)
	{
		std::deque<int>::iterator pos = binarySearchInsert(
			mainChain, straggler, mainChain.end());
		mainChain.insert(pos, straggler);
	}

	container = mainChain;
}

/* ===================== Sort Entry Point ===================== */

void PmergeMe::sort()
{
	// Sort with std::vector
	clock_t start = clock();
	fordJohnsonSort(_vec);
	clock_t end = clock();
	_vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	// Sort with std::deque
	start = clock();
	fordJohnsonSort(_deq);
	end = clock();
	_deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

/* ===================== Display ===================== */

void PmergeMe::displayResults() const
{
	std::cout << "Before:";
	for (size_t i = 0; i < _unsorted.size(); i++)
		std::cout << " " << _unsorted[i];
	std::cout << std::endl;

	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque  : " << _deqTime << " us" << std::endl;
}
