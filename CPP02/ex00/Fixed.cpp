/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:41 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/12 20:10:09 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << "\n";
	this->value = 0;
}

Fixed::Fixed (Fixed& f)
{
	std::cout << "Copy constructor called" << "\n";
	this->value = f.getRawBits();
}

Fixed &Fixed::operator=(Fixed &f)
{
	std::cout << "Copy assignment operator called" << "\n";
	this->value = f.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << "\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << "\n";
	return (this->value);
}

void    Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << "\n";
	this->value = raw;
}
