/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:45:29 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 17:37:09 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string	type;

	public:
		Animal( void );
		Animal( const Animal &f );
		Animal &operator=( const Animal &f );
		virtual ~Animal( void );

		std::string	getType( void ) const;

		virtual void	makeSound( void ) const;
};
