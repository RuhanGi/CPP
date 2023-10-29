/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:54:12 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/27 16:13:26 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

#define GREY	"\x1B[30m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define PURPLE	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define RESET	"\x1B[0m"

// #define MIN -1000
// #define MAX 1000

#define MIN -2147483648
#define MAX 2147483647

class Span {
	private:
		const unsigned int	N;
		std::vector<int>	vec;

	public:
		Span( unsigned int n );

		Span( void );
		Span( const Span &f );
		Span &operator=( const Span &f );
		~Span( void );

		unsigned int	getN( void ) const ;

		void	addNumber( int num );
		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void );

		template <typename Iter>
		void	addNumber(Iter begin, Iter end)
		{
			if (begin >= end)
				return ;
			if (this->vec.size() + std::distance(begin, end) > getN())
				throw Span::SpanFull();
			this->vec.insert(this->vec.end(), begin, end);
		}
		
		class SpanFull : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class SpanShorted : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
