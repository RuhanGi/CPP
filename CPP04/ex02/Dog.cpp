/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:02:07 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:27:41 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << "\x1B[33m" << "Default Dog constructor called" << "\x1B[0m\n";
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog( const Dog &f ) : AAnimal()
{
	std::cout << "\x1B[33m" << "Copy Dog constructor called" << "\x1B[0m\n";
	*this = f;
}

Dog &Dog::operator=( const Dog &f )
{
	std::cout << "\x1B[33m" << "Copy Dog assignment operator called" << "\x1B[0m\n";
	this->type = f.type;
	this->brain = new Brain(*(f.brain));
	return (*this);
}

Dog::~Dog( void )
{
	delete this->brain;
	std::cout << "\x1B[33m" << "Dog Destructor called" << "\x1B[0m\n";
}

void	Dog::makeSound( void ) const
{
	std::cout << "\x1B[32m" << " ( barkkk ) " << "\x1B[0m";
}
