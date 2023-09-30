/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:01:13 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 18:40:24 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "\x1B[33m" << "Default Brain constructor called" << "\x1B[0m\n";
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "IdeaX";
}

Brain::Brain( const Brain &f )
{
	std::cout << "\x1B[33m" << "Copy Brain constructor called" << "\x1B[0m\n";
	*this = f;
}

Brain &Brain::operator=( const Brain &f )
{
	std::cout << "\x1B[33m" << "Copy Brain assignment operator called" << "\x1B[0m\n";
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = f.ideas[i];
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "\x1B[33m" << "Brain Destructor called" << "\x1B[0m\n";
	delete[] (this->ideas);
}

std::string *Brain::getIdeas( void )
{
	return (this->ideas);
}