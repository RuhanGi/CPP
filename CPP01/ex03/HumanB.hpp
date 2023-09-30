/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:57 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/11 13:08:04 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class	HumanB {
	private:
		std::string name;
		Weapon		*weap;

	public:
		HumanB( std::string n );
        ~HumanB( void );

		std::string getName( void );
		Weapon	*getWeapon( void );

		void	setName( std::string n );
		void	setWeapon( Weapon &w );
		
		void	attack( void );
};

#endif
