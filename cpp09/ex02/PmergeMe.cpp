#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <limits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

void PmergeMe::validateInput(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::stringstream ss(av[i]);
		int num;
		ss >> num;
		if (ss.fail() || !ss.eof() || num < 0 || num > 2147483647)
		{
			std::cerr << "Error: Invalid input." << std::endl;
			throw std::exception();
		}
		vec.push_back(num);
		deq.push_back(num);
	}
}

template <typename T>
void PmergeMe::insertionSort(T& container, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = container[i];
		int j = i - 1;
		while (j >= left && container[j] > key)
		{
			container[j + 1] = container[j];
			--j;
		}
		container[j + 1] = key;
	}
}

template <typename T>
void PmergeMe::merge(T& container, int left, int mid, int right)
{
	T temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		if (container[i] <= container[j])
			temp[k++] = container[i++];
		else
			temp[k++] = container[j++];
	}
	while (i <= mid)
		temp[k++] = container[i++];
	while (j <= right)
		temp[k++] = container[j++];
	for (i = 0; i < k; ++i)
		container[left + i] = temp[i];
}

template <typename T>
void PmergeMe::fordJohnsonSort(T& container, int left, int right)
{
	if (left >= right) return;

	const int threshold = 16;
	if (right - left + 1 <= threshold)
	{
		insertionSort(container, left, right);
		return;
	}

	int mid = left + (right - left) / 2;
	fordJohnsonSort(container, left, mid);
	fordJohnsonSort(container, mid + 1, right);

	merge(container, left, mid, right);
}

void PmergeMe::sort(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: No sequence provided" << std::endl;
		return;
	}

	clock_t vec_start_total = clock();

	try
	{
		validateInput(ac, av);
	}
	catch (const std::exception&)
	{
		return;
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	clock_t vec_sort_start = clock();
	fordJohnsonSort(vec, 0, vec.size() - 1);
	clock_t vec_sort_end = clock();

	clock_t vec_end_total = clock();

	double vec_sort_time = static_cast<double>(vec_sort_end - vec_sort_start) * 1000000 / CLOCKS_PER_SEC;
	double vec_total_time = static_cast<double>(vec_end_total - vec_start_total) * 1000000 / CLOCKS_PER_SEC;

	clock_t deq_start_total = clock();

	clock_t deq_sort_start = clock();
	fordJohnsonSort(deq, 0, deq.size() - 1);
	clock_t deq_sort_end = clock();

	clock_t deq_end_total = clock();

	double deq_sort_time = static_cast<double>(deq_sort_end - deq_sort_start) * 1000000 / CLOCKS_PER_SEC;
	double deq_total_time = static_cast<double>(deq_end_total - deq_start_total) * 1000000 / CLOCKS_PER_SEC;

	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vec_total_time << " microsecond (sort: " << vec_sort_time << " microsecond)" << std::endl;

	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deq_total_time << " microsecond (sort: " << deq_sort_time << " microsecond)" << std::endl;
}
