/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:06:41 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 11:35:17 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "\x1B[33mScavTrap Default constructor called" << "\x1B[0m\n";
	this->Name = "Unnamed ScavTrap";
	this->Hit_points = ScavTrap::hp;
	this->Energy_points = ScavTrap::ep;
	this->Attack_damage = ScavTrap::ad;
	this->keeping = false;
}

ScavTrap::ScavTrap(const ScavTrap &f)
{
	std::cout << "\x1B[33mScavTrap Copy constructor called" << "\x1B[0m\n";
	*this = f;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f)
{
	std::cout << "\x1B[33mScavTrap Copy assignment operator called" << "\x1B[0m\n";
	this->Name = f.Name;
	this->Hit_points = f.Hit_points;
	this->Energy_points = f.Energy_points;
	this->Attack_damage = f.Attack_damage;
	this->keeping = f.keeping;
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "\x1B[33mScavTrap Destructor called" << "\x1B[0m\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\x1B[33mScavTrap constructor called" << "\x1B[0m\n";
	this->Name = name;
	this->Hit_points = ScavTrap::hp;
	this->Energy_points = ScavTrap::ep;
	this->Attack_damage = ScavTrap::ad;
	this->keeping = false;
}

void ScavTrap::attack(const std::string& target)
{
	if (getHit() == 0)
		std::cout << "\x1B[31m" << getName() << " is dead!\x1B[0m\n";
	else if (getEnergy() == 0)
		std::cout << "\x1B[31m" << getName() << " has no Energy! Can't Attack!\x1B[0m\n";
	else
	{
		std::cout << "\x1B[32mST " << getName() << " attacks " << target;
		std::cout << ", causing " << getAttack() << " points of damage!\x1B[0m\n";
		this->Energy_points--;
	}
}

void ScavTrap::guardGate( void )
{
	this->keeping = true;
	std::cout << "\x1B[32m" << getName() << " is gatekeeping!\x1B[0m\n";
}

