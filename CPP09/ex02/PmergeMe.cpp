/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:23:45 by mgoltay           #+#    #+#             */
/*   Updated: 2023/11/23 21:11:41 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

unsigned int	PmergeMe::parse(char *str)
{
	if (!str || !str[0])
		throw PmergeMe::InvalidArgument();

	unsigned long nbr = 0;
	int	i = 0;
	while (std::isspace(str[i])) i++;
	if (str[i] == '+') i++;
	do
	{
		if (!isdigit(str[i]))
			throw PmergeMe::InvalidArgument();
		nbr = nbr * 10 + (str[i++] - '0');
		if (nbr > UINT_MAX)
			throw PmergeMe::InvalidArgument();
	} while (str[i]);
	if (nbr == 0)
		throw PmergeMe::InvalidArgument();
	return (nbr);
}

// * List implements the algorithm not in a generic function due to the lack of its iterators ability to be added with numbers
std::list<unsigned int>	PmergeMe::listMergeSort(std::list<unsigned int> lst)
{
	if (lst.size() <= MAXSIZE)
		return (insertionSort(lst));
	
	std::list<unsigned int>::iterator mid = lst.begin();
	std::advance(mid, lst.size() / 2);

	std::list<unsigned int>	first(lst.begin(), mid);
	std::list<unsigned int>	second(mid, lst.end());

	return (merge(listMergeSort(first), listMergeSort(second)));
}

// * Template Function used for vector as deque can also be tested
PmergeMe::PmergeMe( char *strs[], int len )
{
	unsigned int	nbr;

	for (this->size = 0; this->size < (unsigned int) len; this->size++)
	{
		nbr = parse(strs[this->size]);
		this->vec.push_back(nbr);
		// this->deq.push_back(nbr);
		this->lst.push_back(nbr);
	}

	std::cout << GREY "Before:\t" << print(this->vec) << RESET "\n";

	clock_t	start = clock();
	this->vec = mergeSort(this->vec);
	this->vecms = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;

	// start = clock();
	// this->deq = mergeSort(this->deq);
	// this->deqms = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;

	start = clock();
	this->lst = listMergeSort(this->lst);
	this->lstms = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;

	isSorted(this->vec);
	// isSorted(this->deq);
	isSorted(this->lst);	

	std::cout << GREEN " After:\t" << print(this->vec) << RESET "\n";
	std::cout << YELLOW "Time to process a range of " BLUE << this->size << YELLOW " elements with " PURPLE "std::vector" YELLOW " is \t" CYAN << this->vecms << "\t ms" RESET "\n";
	// std::cout << YELLOW "Time to process a range of " BLUE << this->size << YELLOW " elements with " PURPLE "std::deque " YELLOW " is \t" CYAN << this->deqms << "\t ms" RESET "\n";
	std::cout << YELLOW "Time to process a range of " BLUE << this->size << YELLOW " elements with " PURPLE "std::list  " YELLOW " is \t" CYAN << this->lstms << "\t ms" RESET "\n";
}

PmergeMe::PmergeMe( void )
{

}

PmergeMe::PmergeMe( const PmergeMe &f )
{
	*this = f;
}

PmergeMe &PmergeMe::operator=( const PmergeMe &f )
{
	(void) f;
	return (*this);
}

PmergeMe::~PmergeMe( void ) 
{
	
}

const char *PmergeMe::Unsorted::what() const throw()
{
	return ("Sorting Unsuccessful!");
}

const char *PmergeMe::InvalidArgument::what() const throw()
{
	return ("Invalid Argument!");
}