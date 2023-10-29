/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:12:52 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/27 17:41:11 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <stack>
#include <list>

#define GREY	"\x1B[30m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define PURPLE	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define RESET	"\x1B[0m"

#define SIZE 10

#define MIN -1000
#define MAX 1000

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack( void ) {};
		MutantStack( const MutantStack &f ) {*this = f;};
		MutantStack &operator=( const MutantStack &f ) {(void) f;};
		~MutantStack( void ) {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}

		reverse_iterator	rbegin()
		{
			return (this->c.rbegin());
		}

		reverse_iterator	rend()
		{
			return (this->c.rend());
		}

		const_iterator	cbegin()
		{
			return (this->c.cbegin());
		}

		const_iterator	cend()
		{
			return (this->c.cend());
		}

		const_reverse_iterator	crbegin()
		{
			return (this->c.crbegin());
		}

		const_reverse_iterator	crend()
		{
			return (this->c.crend());
		}
};
