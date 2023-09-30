/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:57:34 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 15:04:40 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Character : public ICharacter
{	
	private:
		std::string const	name;
		AMateria			*inv[4];

	public:
		Character(std::string const & n);

		Character( void );
		Character( const Character &f );
		Character &operator=( const Character &f );
		~Character( void );

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
