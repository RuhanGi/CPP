/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:56:38 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 17:55:28 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "\x1B[33m" << "Default WrongAnimal constructor called" << "\x1B[0m\n";
	this->type = "WrongDefault";
}

WrongAnimal::WrongAnimal( const WrongAnimal &f )
{
	std::cout << "\x1B[33m" << "Copy WrongAnimal constructor called" << "\x1B[0m\n";
	*this = f;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &f )
{
	std::cout << "\x1B[33m" << "Copy WrongAnimal assignment operator called" << "\x1B[0m\n";
	this->type = f.type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "\x1B[33m" << "WrongAnimal Destructor called" << "\x1B[0m\n";
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "\x1B[32m" << " ( the void speaks ) " << "\x1B[0m";
}
