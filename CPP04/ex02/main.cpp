/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:43:45 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:18:43 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define LEN 6

int	main(void)
{
	// const AAnimal* meta = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	std::cout << "\n\n";

	// delete meta;
	delete j;
	delete i;

	std::cout << "\n";

	// AAnimal a;
	Cat c;
	Dog d;
	
	// std::cout << "\n" << a.getType() << " ";
	// a.makeSound();
	std::cout << "\n" << c.getType() << " ";
	c.makeSound();
	std::cout << "\n" << d.getType() << " ";
	d.makeSound();
	std::cout << "\n\n";

	const WrongAnimal* wrAnimal = new WrongAnimal();
	const WrongAnimal* wrcat = new WrongCat();

	std::cout << "\n" << wrAnimal->getType() << " ";
	wrAnimal->makeSound();
	std::cout << "\n" << wrcat->getType() << " ";
	wrcat->makeSound();
	std::cout << "\n\n";

	delete wrAnimal;
	delete wrcat;
	
	
	return (0);
}
