/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:40 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 18:13:04 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string t )
{
	this->type = t;
}

Weapon::~Weapon( void )
{
	
}

const std::string &Weapon::getType( void )
{
	return (this->type);
}

void	Weapon::setType( std::string str )
{
	this->type = str;
}