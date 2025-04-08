#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;

		void validateInput(int ac, char **av);
		template <typename T>
		void fordJohnsonSort(T& container, int left, int right);
		template <typename T>
		void insertionSort(T& container, int left, int right);
		template <typename T>
		void merge(T& container, int left, int mid, int right);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);

		void sort(int ac, char **av);
};

#endif