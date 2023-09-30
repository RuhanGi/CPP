/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:55:46 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:10:41 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	std::cout << "\x1B[33m" << "Default Ice constructor called" << "\x1B[0m\n";
}

Ice::Ice( const Ice &f ) : AMateria(f.getType())
{
	std::cout << "\x1B[33m" << "Copy Ice constructor called" << "\x1B[0m\n";
}

Ice &Ice::operator=( const Ice &f )
{
	std::cout << "\x1B[33m" << "Copy Ice assignment operator called for ";
	std::cout << f.getType() << "\x1B[0m\n";
	return (*this);
}

Ice::~Ice( void )
{
	std::cout << "\x1B[33m" << "Ice Destructor called" << "\x1B[0m\n";
}

Ice *Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "\x1B[32m" << this->type << " used on " << target.getName() << "\x1B[0m\n";
}
