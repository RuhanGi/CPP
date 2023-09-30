/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:32:51 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/16 18:33:06 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	std::cout << "\x1B[33mDefault constructor called" << "\x1B[0m\n";
	this->Name = "Unnamed ClapTrap";
	this->Hit_points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
}

ClapTrap::ClapTrap( const ClapTrap& f )
{
	std::cout << "\x1B[33mCopy constructor called" << "\x1B[0m\n";
	*this = f;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &f )
{
	std::cout << "\x1B[33mCopy assignment operator called" << "\x1B[0m\n";
	this->Name = f.Name;
	this->Hit_points = f.Hit_points;
	this->Energy_points = f.Energy_points;
	this->Attack_damage = f.Attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "\x1B[33mDestructor called" << "\x1B[0m\n";
}

ClapTrap::ClapTrap( std::string name )
{
	std::cout << "\x1B[33mConstructor called" << "\x1B[0m\n";
	this->Name = name;
	this->Hit_points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
}

std::string ClapTrap::getName( void )
{
	return (this->Name);
}

unsigned int	ClapTrap::getHit( void )
{
	return (this->Hit_points);
}

unsigned int	ClapTrap::getEnergy( void )
{
	return (this->Energy_points);
}

int	ClapTrap::getAttack( void )
{
	return (this->Attack_damage);
}

void	ClapTrap::setName( std::string name )
{
	this->Name = name;
}

void	ClapTrap::setHit( unsigned int h )
{
	this->Hit_points = h;
}

void	ClapTrap::setEnergy( unsigned int e )
{
	this->Energy_points = e;
}

void	ClapTrap::setAttack( int a )
{
	this->Attack_damage = a;
}

void ClapTrap::attack(const std::string& target)
{
	if (getHit() == 0)
		std::cout << "\x1B[31mClapTrap " << getName() << " is dead!\x1B[0m\n";
	else if (getEnergy() == 0)
		std::cout << "\x1B[31mClapTrap " << getName() << " has no Energy! Can't Attack!\x1B[0m\n";
	else
	{
		std::cout << "\x1B[32mClapTrap " << getName() << " attacks " << target;
		std::cout << ", causing " << getAttack() << " points of damage!\x1B[0m\n";
		this->Energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (getHit() == 0)
		std::cout << "\x1B[31m" << getName() << " is dead!\x1B[0m\n";
	else
		std::cout << "\x1B[31m" << getName() << " has lost " << amount << " hit points!\x1B[0m";
	if (getHit() <= amount && getHit())
	{
		std::cout << " \x1B[31m" << getName() << " has died!\x1B[0m\n";
		this->Hit_points = 0;
	}
	else
	{
		this->Hit_points -= amount;
		std::cout << " " << getHit() << " left!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (getHit() == 0)
		std::cout << "\x1B[31m" << getName() << " is dead!\x1B[0m\n";
	else if (getEnergy() == 0)
		std::cout << "\x1B[31m" << getName() << " has no Energy! Can't Repair!\x1B[0m\n";
	else
	{
		std::cout << "\x1B[32m" << getName() << " repairs " << amount << " hit points!\x1B[0m";
		this->Hit_points += amount;
		std::cout << " " << getHit() << " left!\n";
		this->Energy_points--;
	}
}
