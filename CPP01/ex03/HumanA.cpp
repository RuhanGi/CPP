/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:46 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 18:24:42 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string n, Weapon &w ) : name(n), weap(w)
{
	
}

HumanA::~HumanA( void )
{
	
}

std::string HumanA::getName( void )
{
	return (this->name);
}

Weapon HumanA::getWeapon( void )
{
	return (this->weap);
}

void	HumanA::setName( std::string n )
{
	this->name = n;
}

void	HumanA::setWeapon( Weapon w )
{
	this->weap = w;
}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " << this->weap.getType() << "\n";
}
