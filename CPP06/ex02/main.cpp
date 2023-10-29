/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:30:31 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/07 13:12:25 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base	*generate(void)
{
	int	random = rand();

	if (random % 3 == 0)
		return (dynamic_cast<Base *>(new A));
	else if (random % 3 == 1)
		return (dynamic_cast<Base *>(new B));
	else
		return (dynamic_cast<Base *>(new C));
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "This is of subclass A!" << "\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "This is of subclass B!" << "\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "This is of subclass C!" << "\n";
	else
		std::cout << "This is of neither subclass A, B, or C!" << "\n";
}

void	identify(Base& p)
{
	for (int i = 0; i < 3; i++)
	{
		try
		{
			if (i == 0)
			{
				(void) dynamic_cast<A &>(p);
				std::cout << "This is of subclass A!" << "\n";
			}
			else if (i == 1)
			{
				(void) dynamic_cast<B &>(p);
				std::cout << "This is of subclass B!" << "\n";
			}
			else
			{
				(void) dynamic_cast<C &>(p);
				std::cout << "This is of subclass C!" << "\n";
			}
			return ;
		}
		catch (const std::exception & e)
		{
			if (i == 2)
				std::cout << "This is of neither subclass A, B, or C!" << "\n";
		}
	}
}

int main(void)
{
	srand(time(NULL));
	Base	*b1 = generate();
	Base	*b2 = generate();
	Base	*b3 = generate();
	
	std::cout << "\x1B[32m" << "Pointers: " << "\x1B[0m\n";
	identify(b1);
	identify(b2);
	identify(b3);

	std::cout << "\x1B[32m" << "\nReferences: " << "\x1B[0m\n";
	identify(*b1);
	identify(*b2);
	identify(*b3);

	delete b1;
	delete b2;
	delete b3;

	return (0);
}
