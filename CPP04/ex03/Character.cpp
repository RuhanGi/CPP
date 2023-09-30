/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:57:31 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:15:31 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & n) : name(n)
{
	std::cout << "\x1B[33m" << "Character constructor called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

Character::Character( void ) : name("Unnamed")
{
	std::cout << "\x1B[33m" << "Default Character constructor called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

Character::Character( const Character &f ) : name(f.name)
{
	std::cout << "\x1B[33m" << "Copy Character assigment operator called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
	{
		if (f.inv[i])
			this->inv[i] = f.inv[i]->clone();
		else
			this->inv[i] = NULL;
	}
}

Character &Character::operator=( const Character &f )
{
	std::cout << "\x1B[33m" << "Copy Character assigment operator called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i])
			delete this->inv[i];
		if (f.inv[i])
			this->inv[i] = f.inv[i]->clone();
		else
			this->inv[i] = NULL;
	}
	return (*this);
}

Character::~Character( void )
{
	std::cout << "\x1B[33m" << "Character Destructor called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
		if (this->inv[i])
			delete this->inv[i];
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int	i = 0;
	while (i < 4 && this->inv[i])
		i++;
	if (i < 4)
	{
		std::cout << "\x1B[32m" << "Equipped " << m->getType() << "!\x1B[0m\n";
		this->inv[i] = m;
	}
	else
		std::cout << "\x1B[31m" << "Inventory Full!" << "\x1B[0m\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inv[idx])
	{
		std::cout << "\x1B[32m" << "Unequipped " << this->inv[idx]->getType() << "!\x1B[0m\n";
		this->inv[idx] = NULL;
	}
	else
		std::cout << "\x1B[31m" << "Invalid or Empty Index!" << "\x1B[0m\n";
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inv[idx])
		this->inv[idx]->use(target);
	else
		std::cout << "\x1B[31m" << "Invalid or Empty Index!" << "\x1B[0m\n";
}
