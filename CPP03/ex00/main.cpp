/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:32:20 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/16 18:32:40 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
    ClapTrap a;
    ClapTrap b = ClapTrap(a);
	ClapTrap c = b;
    c.setName("Clappy");

    c.attack("Zombie");
    c.takeDamage(9);
    c.beRepaired(7);
    c.attack("Robot");
    c.beRepaired(7);
    c.attack("Robot");
    c.beRepaired(7);
    c.attack("Robot");
    c.beRepaired(7);
    c.attack("Robot");
    c.beRepaired(7);
    c.attack("Robot");
    c.beRepaired(7);
    c.attack("Robot");
}
