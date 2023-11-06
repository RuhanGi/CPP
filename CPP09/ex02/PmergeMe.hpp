/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:23:48 by mgoltay           #+#    #+#             */
/*   Updated: 2023/11/03 21:40:21 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <climits>
#include <vector>
#include <deque>
#include <ctime>
#include <list>

#define GREY	"\x1B[30m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define PURPLE	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define RESET	"\x1B[0m"

#define MAXSIZE 1

class PmergeMe
{
	private:
		unsigned int	size;
	
		std::vector<unsigned int>	vec;
		// std::deque<unsigned int>	deq;
		std::list<unsigned int>		lst;
		
		double	vecms;
		// double	deqms;
		double	lstms;

	public:
		//  * CONSTRUCTOR * //
		PmergeMe( char *strs[], int len );

		// * ORTHODOX CANONICAL FORM * //
		PmergeMe( void );
		PmergeMe( const PmergeMe &f );
		PmergeMe &operator=( const PmergeMe &f );
		~PmergeMe( void );

		// * USED FUNCTIONS * //
		unsigned int	parse(char *str);
		std::list<unsigned int>	listMergeSort(std::list<unsigned int> lst);

		// * TEMPLATE FUNCTIONS * //
		template <typename T>
		void	swap(T &a, T &b)
		{
			T temp = a;
			a = b;
			b = temp;
		}

		template <typename T>
		void	move(T &dest, T &source)
		{
			if (source.empty())
				return ;
			dest.push_back(source.front());
			source.erase(source.begin());
		}

		template <typename T>
		T	&insertionSort( T &container )
		{
			for (typename T::iterator it = container.begin(); it != container.end(); it++)
			{
				for (typename T::iterator needle = it; needle-- != container.begin(); )
					if (*needle >= *it)
					{
						for (typename T::iterator swaprange = it; swaprange != needle; swaprange--)
							swap(*(--swaprange), *(++swaprange));
						break ;
					}
			}
			return (container);
		}

		template <typename T>
		T	merge( T first, T second )
		{
			T	res;

			while (!first.empty() || !second.empty())
			{
				if (first.empty())
					move(res, second);
				else if (second.empty())
					move(res, first);
				else
					move(res, (first.front() <= second.front()) ? (first) : (second));
			}
			return (res);
		}

		template <typename T>
		T	mergeSort( T container )
		{
			if (container.size() <= MAXSIZE)
				return (insertionSort(container));
			
			T first  = mergeSort(std::vector<unsigned int>(container.begin(), container.begin() + container.size() / 2));
			T second = mergeSort(std::vector<unsigned int>(container.begin() + container.size() / 2, container.end()));

			return (merge(first, second));
		}

		template <typename T>
		std::string	print(T &container)
		{
			for (typename T::iterator it = container.begin(); it != container.end(); it++)
				std::cout << *it << "\t";
			return ("");
		}

		template <typename T>
		void	isSorted(T container)
		{
			if (container.size() != this->size)
				throw PmergeMe::Unsorted();

			for (typename T::iterator it = ++container.begin(); it != container.end(); it++)
				if (*(--it) > *(++it))
					throw PmergeMe::Unsorted();
		}

		class InvalidArgument : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class Unsorted : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
