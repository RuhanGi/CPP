/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:35:37 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 13:57:43 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void )
{
	std::cout << "\x1B[33m" << "Default AMateria constructor called" << "\x1B[0m\n";
}

AMateria::AMateria( std::string const & type ) : type(type)
{
    std::cout << "\x1B[33m" << "AMateria constructor called" << "\x1B[0m\n";
}

AMateria::AMateria( const AMateria &f ) : type(f.type)
{
	std::cout << "\x1B[33m" << "Copy AMateria constructor called" << "\x1B[0m\n";
}

AMateria::~AMateria( void )
{
	std::cout << "\x1B[33m" << "AMateria Destructor called" << "\x1B[0m\n";
}

std::string const &AMateria::getType( void ) const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "\x1B[32m" << this->type << " used on " << target.getName() << "\x1B[0m\n";
}