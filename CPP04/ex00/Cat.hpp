/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:45:36 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 17:36:41 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat( void );
		Cat( const Cat &f );
		Cat &operator=( const Cat &f );
		~Cat( void );

		void	makeSound( void ) const;
};
