/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:53 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 18:45:52 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string n ) : name(n)
{
	
}

HumanB::~HumanB( void )
{
	
}

std::string HumanB::getName( void )
{
	return (this->name);
}

Weapon *HumanB::getWeapon( void )
{
	return (this->weap);
}

void	HumanB::setName( std::string n )
{
	this->name = n;
}

void	HumanB::setWeapon( Weapon &w )
{
	Weapon *ptr = &w;
	this->weap = ptr;
}

void	HumanB::attack( void )
{
	std::cout << this->name << " attacks with their " << this->weap->getType() << "\n";
}