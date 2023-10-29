/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:09:40 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 15:47:03 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "\x1B[33m" << "Default Intern constructor called" << "\x1B[0m\n";
}

Intern::Intern( const Intern &f )
{
	std::cout << "\x1B[33m" << "Copy Intern constructor called" << "\x1B[0m\n";
	*this = f;
}

Intern &Intern::operator=( const Intern &f )
{
	(void) f;

	std::cout << "\x1B[33m" << "Copy Intern assignment operator called" << "\x1B[0m\n";
	return (*this);
}

Intern::~Intern( void )
{
	std::cout << "\x1B[33m" << "Intern Destructor called" << "\x1B[0m\n";
}

std::string	treatstring(std::string name)
{
	for (unsigned long i = 0; i < name.length(); i++)
	{
		if (name[i] == ' ')
			name.erase(i--, 1);
		else
			name[i] = tolower(name[i]);
	}
	return (name);
}

AForm	*newShrubbery( std::string target )
{
	return (new ShrubberyCreationForm(target));
}

AForm		*newRobotomy( std::string target )
{
	return (new RobotomyRequestForm(target));
}

AForm	*newPresident( std::string target )
{
	return (new PresidentialPardonForm(target));
}

AForm    *Intern::makeForm(std::string name, std::string target)
{
	static std::string type[] = {"shrubberycreationform", "robotomyrequestform", "presidentialpardonform"};
	static AForm *(*formfuncs[])(std::string) = {&newShrubbery, &newRobotomy, &newPresident};
	
	name = treatstring(name);
	for (int i = 0; i < 3 && (name.length() > 14); i++)
	{
		if (name.compare(0, name.length(), type[i]) == 0)
		{
			std::cout << "\x1B[32m" << "Intern creates " << type[i] << "\x1B[0m\n";
			return (formfuncs[i](target));
		}
	}
	std::cout << "\x1B[31m" << "Intern could not find appropriate form available!" << "\x1B[0m\n";
	return (NULL);
}
