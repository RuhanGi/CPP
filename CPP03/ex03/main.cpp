/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:32:20 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 11:34:23 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
    ClapTrap a;
    ClapTrap b = ClapTrap(a);
	ClapTrap c = b;
    c.setName("Clappy");

    c.attack("Zombie");
    c.takeDamage(9);
    c.beRepaired(7);


    ScavTrap d = ScavTrap("Scurvy");
    d.attack("Punies");
    d.takeDamage(5);
    d.beRepaired(10);
    d.guardGate();

    FragTrap e = FragTrap("Fraggy");
    e.attack("Puns");
    e.takeDamage(5);
    e.beRepaired(10);
    e.highFivesGuys();

    DiamondTrap f = DiamondTrap("Diamy");
    f.attack("Punt");
    f.takeDamage(5);
    f.beRepaired(10);
    f.guardGate();
    f.highFivesGuys();
    f.whoAmI();
}
