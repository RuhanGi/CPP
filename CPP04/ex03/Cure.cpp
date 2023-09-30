/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:55:56 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:10:50 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	std::cout << "\x1B[33m" << "Default Cure constructor called" << "\x1B[0m\n";
}

Cure::Cure( const Cure &f ) : AMateria(f.getType())
{
	std::cout << "\x1B[33m" << "Copy Cure constructor called" << "\x1B[0m\n";
}

Cure &Cure::operator=( const Cure &f )
{
	std::cout << "\x1B[33m" << "Copy Cure assignment operator called for ";
	std::cout << f.getType() << "\x1B[0m\n";
	return (*this);
}

Cure::~Cure( void )
{
	std::cout << "\x1B[33m" << "Cure Destructor called" << "\x1B[0m\n";
}

Cure *Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "\x1B[32m" << this->type << " used on " << target.getName() << "\x1B[0m\n";
}