/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:23:13 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 11:34:18 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap("Unnamed DiamondTrap")
{
    std::cout << "\x1B[33mDiamondTrap Default constructor called" << "\x1B[0m\n";
	setName("Unnamed DiamondTrap");
	this->Hit_points = FragTrap::hp;
	this->Energy_points = ScavTrap::ep;
	this->Attack_damage = FragTrap::ad;
    this->name = "Unnamed DiamondTrap";
}

DiamondTrap::DiamondTrap(const DiamondTrap &f)
{
    std::cout << "\x1B[33mDiamondTrap Copy constructor called" << "\x1B[0m\n";
	*this = f;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &f)
{
    std::cout << "\x1B[33mDiamondTrap Copy assignment operator called" << "\x1B[0m\n";
	this->Hit_points = f.Hit_points;
	this->Energy_points = f.Energy_points;
	this->Attack_damage = f.Attack_damage;
    this->name = f.name + "_clap_name";
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "\x1B[33mDiamondTrap Destructor called" << "\x1B[0m\n";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    std::cout << "\x1B[33mDiamondTrap constructor called" << "\x1B[0m\n";
	setName(name + "_clap_name");
	this->Hit_points = FragTrap::hp;
	this->Energy_points = ScavTrap::ep;
	this->Attack_damage = FragTrap::ad;
    this->name = name + "_clap_name";
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "\x1B[32mI am DiamondTrap \"" << this->name << "\" also associated ";
	std::cout << "by my ClapTrap name: \"" << getName() << "\".\x1B[0m\n";
}
