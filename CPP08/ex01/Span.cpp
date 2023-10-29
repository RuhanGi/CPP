/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:54:16 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/29 11:54:22 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int n ) : N(n)
{
	// std::cout << YELLOW "Span constructor called" RESET "\n";
	this->vec.reserve(n);
}

Span::Span( void ) : N(0)
{
	// std::cout << YELLOW "Default Span constructor called" RESET "\n";
}

Span::Span( const Span &f ) : N(f.getN())
{
	// std::cout << YELLOW "Copy Span constructor called" RESET "\n";
	*this = f;
}

Span &Span::operator=( const Span &f )
{
	// std::cout << YELLOW "Copy Span assignment operator called" RESET "\n";
	if (this == &f)
		return (*this);
	if (getN() <= f.getN())
		this->vec = f.vec;
	return (*this);
}

Span::~Span( void )
{
	// std::cout << YELLOW "Span Destructor called" RESET "\n";
}

unsigned int	Span::getN( void ) const
{
	return (this->N);
}

void	Span::addNumber( int num )
{
	if (this->vec.size() == getN())
		throw Span::SpanFull();
	this->vec.push_back(num);
}

unsigned int	Span::shortestSpan( void )
{
	if (this->vec.size() < 2)
		throw Span::SpanShorted();
	
	std::sort(this->vec.begin(), this->vec.end());
	unsigned int min = this->vec[1] - this->vec[0];
	for (unsigned long i = 1; i < this->vec.size() - 1; i++)
		min = std::min(min, (unsigned int) (this->vec[i + 1] - this->vec[i]));
	return (min);
}

unsigned int	Span::longestSpan( void )
{
	if (this->vec.size() < 2)
		throw Span::SpanShorted();

	return (*std::max(this->vec.begin(), this->vec.end()) - *std::min(this->vec.begin(), this->vec.end()));
}

const char *Span::SpanFull::what() const throw()
{
	return ("Adding to Full Span Class!");
}

const char *Span::SpanShorted::what() const throw()
{
	return ("Not Enough Elements to Calculate Span!");
}
