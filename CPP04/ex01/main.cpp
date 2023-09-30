/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:43:45 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 16:44:49 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define LEN 6

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\n";

	delete meta;
	delete j;
	delete i;


	Animal a;
	Cat c;
	Dog d;
	
	std::cout << "\n" << a.getType() << " ";
	a.makeSound();
	std::cout << "\n" << c.getType() << " ";
	c.makeSound();
	std::cout << "\n" << d.getType() << " ";
	d.makeSound();
	std::cout << "\n";

	const WrongAnimal* wranimal = new WrongAnimal();
	const WrongAnimal* wrcat = new WrongCat();

	std::cout << wranimal->getType() << " ";
	wranimal->makeSound();
	std::cout << "\n" << wrcat->getType() << " ";
	wrcat->makeSound();
	std::cout << "\n";

	delete wranimal;
	delete wrcat;
	
	Animal *pethouse[LEN];
	for (int i = 0; i < LEN / 2; i++)
		pethouse[i] = new Dog();
	for (int i = LEN / 2; i < LEN; i++)
		pethouse[i] = new Cat();
	for (int i = 0; i < LEN; i++)
		std::cout << pethouse[i]->getType() << "\n";
	for (int i = 0; i < LEN; i++)
		delete pethouse[i];
	
	return (0);
}
