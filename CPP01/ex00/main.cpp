/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:18:05 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/09 18:17:53 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie a;
	Zombie b = Zombie("Stackie");

	Zombie *c = new Zombie("Heapie");

	std::cout << "\n";
	
	randomChump("Randy");

	std::cout << "\n";
	
	Zombie *d = newZombie("Heaped-Z");

	std::cout << "\n";

	delete c;
	delete d;

	std::cout << "\n";
	return (0);
}
