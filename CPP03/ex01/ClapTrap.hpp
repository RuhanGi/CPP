/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:32:57 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/16 18:33:03 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {
	protected:
		std::string Name;
		unsigned int Hit_points;
		unsigned int Energy_points;
		int Attack_damage;

	public:
		ClapTrap( void );
		ClapTrap( const ClapTrap& f );
		ClapTrap &operator=( const ClapTrap &f );
		~ClapTrap( void );

		ClapTrap( std::string name );

		std::string getName( void );
		unsigned int	getHit( void );
		unsigned int	getEnergy( void );
		int	getAttack( void );

		void	setName( std::string name );
		void	setHit( unsigned int h );
		void	setEnergy( unsigned int e );
		void	setAttack( int s );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
