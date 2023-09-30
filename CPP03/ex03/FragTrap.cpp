/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:11:32 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 11:32:38 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "\x1B[33mFragTrap Default constructor called" << "\x1B[0m\n";
	this->Name = "Unnamed FragTrap";
	this->Hit_points = FragTrap::hp;
	this->Energy_points = FragTrap::ep;
	this->Attack_damage = FragTrap::ad;
}

FragTrap::FragTrap(const FragTrap &f): ClapTrap(f)
{
	std::cout << "\x1B[33mFragTrap Copy constructor called" << "\x1B[0m\n";
	*this = f;
}

FragTrap &FragTrap::operator=(const FragTrap &f)
{
	std::cout << "\x1B[33mFragTrap Copy assignment operator called" << "\x1B[0m\n";
	this->Name = f.Name;
	this->Hit_points = f.Hit_points;
	this->Energy_points = f.Energy_points;
	this->Attack_damage = f.Attack_damage;
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "\x1B[33mFragTrap Destructor called" << "\x1B[0m\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\x1B[33mFragTrap constructor called" << "\x1B[0m\n";
	this->Name = name;
	this->Hit_points = FragTrap::hp;
	this->Energy_points = FragTrap::ep;
	this->Attack_damage = FragTrap::ad;
}

void FragTrap::attack(const std::string& target)
{
	if (getHit() == 0)
		std::cout << "\x1B[31mFragTrap " << getName() << " is dead!\x1B[0m\n";
	else if (getEnergy() == 0)
		std::cout << "\x1B[31mFragTrap " << getName() << " has no Energy! Can't Attack!\x1B[0m\n";
	else
	{
		std::cout << "\x1B[32mFragTrap " << getName() << " attacks " << target;
		std::cout << ", causing " << getAttack() << " points of damage!\x1B[0m\n";
		this->Energy_points--;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "\x1B[32m" << getName() << " high fives ALL the guys!\x1B[0m\n";
}
