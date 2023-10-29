/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:59:41 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 15:52:09 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	b = Bureaucrat("Burey", 6);
		Intern		i;

		AForm *s;
		AForm *r;
		AForm *p;

		s = i.makeForm("ShrubberyCreationForm", "TargetTest");
		r = i.makeForm("RobotomyRequestForm", "TargetTest");
		p = i.makeForm("PresidentialPardonForm", "TargetTest");
	
		if (s)
		{
			b.signForm(s);
			b.executeForm(*s);
		}

		if (r)
		{
			b.signForm(r);
			b.executeForm(*r);
		}

		if (p)
		{		
			b.signForm(p);
			b.increment();
			b.executeForm(*p);
		}

		delete s;
		delete r;
		delete p;
	}
	catch (std::exception & e)
	{
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m\n";
		return (1);
	}
	return (0);
}
