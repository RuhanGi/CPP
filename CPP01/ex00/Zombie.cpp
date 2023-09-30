/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:15:19 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/09 17:59:59 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string n)
{
	this->name = n;
	std::cout << "\x1B[32m" << this->name << " entered!\x1B[97m\n";
}

Zombie::Zombie( void )
{
	this->name = "";
	std::cout << "\x1B[32mNew Zombie entered!\x1B[97m\n";
}

Zombie::~Zombie( void )
{
	if (this->name.length() == 0)
		std::cout << "\x1B[31mUnnamed Zombie died!\x1B[97m\n";
	else
		std::cout << "\x1B[31m" << this->name << " died!\x1B[97m\n";
}

std::string Zombie::getName( void )
{
	return (this->name);
}

void    Zombie::setName( std::string n )
{
	this->name = n;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
