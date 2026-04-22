#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <stdexcept>
#include <utility>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void parseArgs(int argc, char **argv);
	void sort();
	void displayResults() const;

private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;
	std::vector<int>	_unsorted;
	double				_vecTime;
	double				_deqTime;

	// Ford-Johnson (merge-insert sort) for std::vector
	void	fordJohnsonSort(std::vector<int> &container);
	void	fjInsert(std::vector<int> &mainChain,
				const std::vector<int> &pend,
				const std::vector<size_t> &jacobOrder);

	// Ford-Johnson (merge-insert sort) for std::deque
	void	fordJohnsonSort(std::deque<int> &container);
	void	fjInsert(std::deque<int> &mainChain,
				const std::deque<int> &pend,
				const std::deque<size_t> &jacobOrder);

	// Jacobsthal number generation
	std::vector<size_t>		generateJacobInsertionOrder(size_t n);
	std::deque<size_t>		generateJacobInsertionOrderDeque(size_t n);

	// Binary search helpers
	std::vector<int>::iterator	binarySearchInsert(std::vector<int> &chain,
								int value,
								std::vector<int>::iterator end);
	std::deque<int>::iterator	binarySearchInsert(std::deque<int> &chain,
								int value,
								std::deque<int>::iterator end);
};

#endif
