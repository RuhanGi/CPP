/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:07:55 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 14:54:46 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	std::cout << "\x1B[33m" << "Default MateriaSource constructor called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource &f )
{
	std::cout << "\x1B[33m" << "Copy MateriaSource constructor called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
	{
		if (f.inv[i])
			this->inv[i] = f.inv[i]->clone();
		else
			this->inv[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=( const MateriaSource &f )
{
	std::cout << "\x1B[33m" << "Copy MateriaSource assigment operator called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i])
			delete this->inv[i];
		this->inv[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
		if (f.inv[i])
			this->inv[i] = f.inv[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	std::cout << "\x1B[33m" << "MateriaSource Destructor called" << "\x1B[0m\n";
	for (int i = 0; i < 4; i++)
		if (this->inv[i])
			delete this->inv[i];
}

void MateriaSource::learnMateria(AMateria *src)
{
	int	i = 0;
	while (this->inv[i] && i < 4)
		i++;
	if (i < 4)
		this->inv[i] = src;
	else
		std::cout << "\x1B[31m" << "Can't add more than FOUR Materia!" << "\x1B[0m\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4 && this->inv[i]; i++)
		if (this->inv[i]->getType() == type)
			return (this->inv[i]->clone());
	std::cout << "\x1B[31m" << type << " does not exist!" << "\x1B[0m\n";
	return (NULL);
}
