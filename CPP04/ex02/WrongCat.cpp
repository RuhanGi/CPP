/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:02:00 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:35:07 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	std::cout << "\x1B[33m" << "Default WrongCat constructor called" << "\x1B[0m\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &f ) : WrongAnimal()
{
	std::cout << "\x1B[33m" << "Copy WrongCat constructor called" << "\x1B[0m\n";
	*this = f;
}

WrongCat &WrongCat::operator=( const WrongCat &f )
{
	std::cout << "\x1B[33m" << "Copy WrongCat assignment operator called" << "\x1B[0m\n";
	this->type = f.type;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "\x1B[33m" << "WrongCat Destructor called" << "\x1B[0m\n";
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "\x1B[32m" << " ( meowww ) " << "\x1B[0m";
}