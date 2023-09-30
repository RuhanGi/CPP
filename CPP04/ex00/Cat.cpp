/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:02:00 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:24:18 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << "\x1B[33m" << "Default Cat constructor called" << "\x1B[0m\n";
	this->type = "Cat";
}

Cat::Cat( const Cat &f ) : Animal()
{
	std::cout << "\x1B[33m" << "Copy Cat constructor called" << "\x1B[0m\n";
	*this = f;
}

Cat &Cat::operator=( const Cat &f )
{
	std::cout << "\x1B[33m" << "Copy Cat assignment operator called" << "\x1B[0m\n";
	this->type = f.type;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "\x1B[33m" << "Cat Destructor called" << "\x1B[0m\n";
}

void	Cat::makeSound( void ) const
{
	std::cout << "\x1B[32m" << " ( meowww ) " << "\x1B[0m";
}
