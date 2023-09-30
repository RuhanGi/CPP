/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:56:00 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/24 17:23:28 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{	
	public:
		Cure( void );
		Cure( const Cure &f );
		Cure &operator=( const Cure &f );
		~Cure( void );

		Cure *clone() const;
		void use(ICharacter& target);
};
