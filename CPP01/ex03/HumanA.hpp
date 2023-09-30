/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:32 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 18:22:41 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class	HumanA {
	private:
		std::string name;
		Weapon		&weap;

	public:
		HumanA( std::string n, Weapon &w );
        ~HumanA( void );

		std::string getName( void );
		Weapon getWeapon( void );

		void	setName( std::string n );
		void	setWeapon( Weapon w );
		
		void	attack( void );
};

#endif
