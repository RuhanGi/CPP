/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:30:01 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/07 11:25:05 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{
	// std::cout << "\x1B[33m" << "Default Serializer constructor called" << "\x1B[0m\n";
}

Serializer::Serializer( const Serializer &f )
{
	// std::cout << "\x1B[33m" << "Copy Serializer constructor called" << "\x1B[0m\n";
	(void) f;
}

Serializer &Serializer::operator=( const Serializer &f )
{
	// std::cout << "\x1B[33m" << "Copy Serializer assignment operator called" << "\x1B[0m\n";
	(void) f;
	return (*this);
}

Serializer::~Serializer( void )
{
	// std::cout << "\x1B[33m" << "Serializer Destructor called" << "\x1B[0m\n";
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
