/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:56:38 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 18:03:16 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
	std::cout << "\x1B[33m" << "Default Animal constructor called" << "\x1B[0m\n";
	this->type = "Default";
}

Animal::Animal( const Animal &f )
{
	std::cout << "\x1B[33m" << "Copy Animal constructor called" << "\x1B[0m\n";
	*this = f;
}

Animal &Animal::operator=( const Animal &f )
{
	std::cout << "\x1B[33m" << "Copy Animal assignment operator called" << "\x1B[0m\n";
	this->type = f.type;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "\x1B[33m" << "Animal Destructor called" << "\x1B[0m\n";
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "\x1B[32m" << " ( the void speaks ) " << "\x1B[0m";
}
