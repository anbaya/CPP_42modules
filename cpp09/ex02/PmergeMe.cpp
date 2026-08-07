#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) : _v(src._v), _d(src._d) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		_v = rhs._v;
		_d = rhs._d;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::validateInput(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		std::string s(av[i]);
		if (s.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < s.size(); j++) {
			if (s[j] < '0' || s[j] > '9')
				throw std::runtime_error("Error");
		}
		long num = std::atol(s.c_str());
		if (num <= 0 || num > 2147483647)
			throw std::runtime_error("Error");
		_v.push_back(static_cast<int>(num));
		_d.push_back(static_cast<int>(num));
	}
}

void PmergeMe::parseAndSort(int ac, char **av) {
	validateInput(ac, av);

	std::cout << "Before:";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << " " << _v[i];
	std::cout << std::endl;

	clock_t t0 = clock();
	fjSort(_v);
	double vecUs = static_cast<double>(clock() - t0) / CLOCKS_PER_SEC * 1e6;

	t0 = clock();
	fjSort(_d);
	double deqUs = static_cast<double>(clock() - t0) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After:";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << " " << _v[i];
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _v.size()
		<< " elements with std::vector : " << vecUs << " us" << std::endl;
	std::cout << "Time to process a range of " << _d.size()
		<< " elements with std::deque  : " << deqUs << " us" << std::endl;
}
