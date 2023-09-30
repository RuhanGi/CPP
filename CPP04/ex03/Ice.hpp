/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:55:50 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/24 17:23:44 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{		
	public:
		Ice( void );
		Ice( const Ice &f );
		Ice &operator=( const Ice &f );
		~Ice( void );

		Ice *clone( void ) const;
		void use(ICharacter& target);
};
