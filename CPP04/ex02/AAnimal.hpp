/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
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

class AAnimal {
	protected:
		std::string	type;

	public:
		AAnimal( void );
		AAnimal( const AAnimal &f );
		AAnimal &operator=( const AAnimal &f );
		virtual ~AAnimal( void );

		virtual std::string	getType( void ) const;

		virtual void	makeSound( void ) const = 0;
};
