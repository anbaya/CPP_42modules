#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <iomanip>

class PmergeMe {

	private:
		std::vector<int>	_v;
		std::deque<int>		_d;

		void	validateInput(int ac, char **av);

		template <typename T>
		static void	fjSort(T& seq);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void	parseAndSort(int ac, char **av);
};

// Ford-Johnson (merge-insertion) sort — templated for both containers
template <typename T>
void PmergeMe::fjSort(T& seq) {
	if (seq.size() <= 1)
		return;

	int n = seq.size();
	bool odd = (n % 2 != 0);
	int stray = odd ? seq[n - 1] : 0;

	// Pair adjacent elements, larger value first
	std::vector<std::pair<int, int> > pairs;
	for (int i = 0; i + 1 < n; i += 2) {
		int hi = seq[i], lo = seq[i + 1];
		if (hi < lo)
			std::swap(hi, lo);
		pairs.push_back(std::make_pair(hi, lo));
	}

	// Recursively sort the larger halves
	T big;
	for (size_t i = 0; i < pairs.size(); i++)
		big.push_back(pairs[i].first);
	fjSort(big);

	// Align pairs to match sorted order of winners
	std::vector<std::pair<int, int> > aligned;
	std::vector<bool> taken(pairs.size(), false);
	for (size_t i = 0; i < big.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (!taken[j] && pairs[j].first == big[i]) {
				aligned.push_back(pairs[j]);
				taken[j] = true;
				break;
			}
		}
	}

	// Main chain: b1 (guaranteed < a1), then all winners a1..aN
	T chain;
	chain.push_back(aligned[0].second);
	for (size_t i = 0; i < aligned.size(); i++)
		chain.push_back(aligned[i].first);

	// Pending elements: b2, b3, ... (smaller halves minus b1)
	std::vector<int> pend;
	for (size_t i = 1; i < aligned.size(); i++)
		pend.push_back(aligned[i].second);

	// Insert pending elements using Jacobsthal-ordered binary insertion
	int pn = pend.size();
	if (pn > 0) {
		std::vector<int> order;
		order.push_back(0);
		int lo = 1, hi = 3;
		while (lo < pn) {
			int cap = (hi > pn) ? pn : hi;
			for (int k = cap - 1; k >= lo; k--)
				order.push_back(k);
			if (cap >= pn)
				break;
			int nxt = hi + 2 * lo;
			lo = hi;
			hi = nxt;
		}
		for (size_t i = 0; i < order.size(); i++) {
			int val = pend[order[i]];
			int win = aligned[order[i] + 1].first;
			typename T::iterator bound = std::find(chain.begin(), chain.end(), win);
			typename T::iterator pos = std::lower_bound(chain.begin(), bound, val);
			chain.insert(pos, val);
		}
	}

	// Insert straggler (unpaired element from odd-sized input)
	if (odd) {
		typename T::iterator pos = std::lower_bound(chain.begin(), chain.end(), stray);
		chain.insert(pos, stray);
	}

	seq = chain;
}

#endif
