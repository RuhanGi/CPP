/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:06:49 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 11:32:06 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	private:
		bool keeping;

	public:
		ScavTrap( void );
		ScavTrap(const ScavTrap &f);
		ScavTrap &operator=(const ScavTrap &f);
		virtual ~ScavTrap( void );

		ScavTrap(std::string name);

		void attack(const std::string& target);
		void guardGate( void );
	
		static const unsigned int hp = 100;
		static const unsigned int ep = 50;
		static const int ad = 20;
};

#endif
