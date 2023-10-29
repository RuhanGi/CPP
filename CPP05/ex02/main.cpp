/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:59:41 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 14:27:51 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat b = Bureaucrat("Burey", 50);

		ShrubberyCreationForm s = ShrubberyCreationForm("Test");

		std::cout << "\x1B[32m" << b << " " << s << "\x1B[0m\n";
		b.signForm(&s);
		std::cout << "\x1B[32m" << b << " " << s << "\x1B[0m\n";
		b.executeForm(s);
		std::cout << "\x1B[32m" << b << " " << s << "\x1B[0m\n";
		
		RobotomyRequestForm r = RobotomyRequestForm("Test");

		std::cout << "\x1B[32m" << b << " " << r << "\x1B[0m\n";
		b.signForm(&r);
		std::cout << "\x1B[32m" << b << " " << r << "\x1B[0m\n";
		// b.increment();b.increment();b.increment();b.increment();b.increment();
		b.executeForm(r);
		std::cout << "\x1B[32m" << b  << " " << r << "\x1B[0m\n";
		
		PresidentialPardonForm p = PresidentialPardonForm("Test");

		std::cout << "\x1B[32m" << b << " " << p << "\x1B[0m\n";
		b.signForm(&p);
		std::cout << "\x1B[32m" << b << " " << p << "\x1B[0m\n";
		b.executeForm(p);
		std::cout << "\x1B[32m" << b << " " << p << "\x1B[0m\n";
		
	}
	catch (std::exception & e)
	{
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m\n";
		return (1);
	}
	return (0);
}
