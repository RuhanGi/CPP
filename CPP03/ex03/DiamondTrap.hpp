/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:23:10 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/20 19:15:55 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string name;

	public:
		DiamondTrap( void );
		DiamondTrap(const DiamondTrap &f);
		DiamondTrap &operator=(const DiamondTrap &f);
		virtual ~DiamondTrap( void );

		DiamondTrap(std::string name);

		void attack(const std::string& target);
		void whoAmI( void );
};

#endif
