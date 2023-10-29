/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:04:33 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/23 20:30:29 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

#define SIZE 5

template <typename T>
class	Array
{
	private:
		T				*arr;
		unsigned int	_size;

	public:
		Array(unsigned int n);
	
		Array( void );
		Array( const Array &f );
		Array &operator=( const Array &f );
		~Array( void );

		unsigned int	size() const ;

		T	&operator[]( const unsigned int i );

		class OutOfBounds : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"
