/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:41 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/15 18:20:03 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << "\n";
	this->value = 0;
}

Fixed::Fixed( const int d )
{
	std::cout << "Int constructor called" << "\n";
	this->value = d << Fixed::bits;
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << "\n";
	this->value = roundf(f * (1 << Fixed::bits));
}

Fixed::Fixed ( const Fixed& f )
{
	std::cout << "Copy constructor called" << "\n";
	*this = f;
}

Fixed &Fixed::operator=( const Fixed &f )
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
	return (this->value);
}

void    Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float) (this->value) / (float)(1 << Fixed::bits));
}

int Fixed::toInt( void ) const
{
	return (this->value >> Fixed::bits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
