/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:56:38 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 18:03:16 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
	std::cout << "\x1B[33m" << "Default AAnimal constructor called" << "\x1B[0m\n";
	this->type = "Default";
}

AAnimal::AAnimal( const AAnimal &f )
{
	std::cout << "\x1B[33m" << "Copy AAnimal constructor called" << "\x1B[0m\n";
	*this = f;
}

AAnimal &AAnimal::operator=( const AAnimal &f )
{
	std::cout << "\x1B[33m" << "Copy AAnimal assignment operator called" << "\x1B[0m\n";
	this->type = f.type;
	return (*this);
}

AAnimal::~AAnimal( void )
{
	std::cout << "\x1B[33m" << "AAnimal Destructor called" << "\x1B[0m\n";
}

std::string	AAnimal::getType( void ) const
{
	return (this->type);
}
