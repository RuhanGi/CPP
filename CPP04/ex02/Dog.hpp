/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:45:42 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/24 15:00:45 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain *brain;

	public:
		Dog( void );
		Dog( const Dog &f );
		Dog &operator=( const Dog &f );
		~Dog( void );

		void	makeSound( void ) const;
};
