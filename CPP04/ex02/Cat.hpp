/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:45:36 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/24 15:00:45 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain *brain;

	public:
		Cat( void );
		Cat( const Cat &f );
		Cat &operator=( const Cat &f );
		~Cat( void );

		void	makeSound( void ) const;
};
