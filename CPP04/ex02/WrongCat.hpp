/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:45:36 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:35:26 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat( void );
		WrongCat( const WrongCat &f );
		WrongCat &operator=( const WrongCat &f );
		~WrongCat( void );
	
		void	makeSound( void ) const;
};
