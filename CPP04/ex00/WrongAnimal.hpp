/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:45:29 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:35:50 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal &f );
		WrongAnimal &operator=( const WrongAnimal &f );
		virtual ~WrongAnimal( void );

		std::string	getType( void ) const;

		void	makeSound( void ) const;
};
