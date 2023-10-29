/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:11:28 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 16:15:28 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "\x1B[33m" << "ShrubberyCreationForm constructor called" << "\x1B[0m\n";
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "\x1B[33m" << "Default ShrubberyCreationForm constructor called" << "\x1B[0m\n";
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &f ) : AForm(f.getName(), f.getSignGrade(), f.getExecGrade())
{
	std::cout << "\x1B[33m" << "Copy ShrubberyCreationForm constructor called" << "\x1B[0m\n";
	*this = f;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &f )
{
	std::cout << "\x1B[33m" << "Copy ShrubberyCreationForm assignment operator called" << "\x1B[0m\n";
	setSigned(f.getSignStatus());
	setTarget(f.getTarget());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "\x1B[33m" << "ShrubberyCreationForm Destructor called" << "\x1B[0m\n";
}

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		return (false);
	std::string s = getTarget() + "_shrubbery";
	const char* str = s.c_str();
	std::ofstream shrubfile(str);
	shrubfile << "               ,@@@@@@@," << "\n";
	shrubfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << "\n";
	shrubfile << "    ,&%%%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << "\n";
	shrubfile << "   ,%&\\%%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << "\n";
	shrubfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << "\n";
	shrubfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << "\n";
	shrubfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << "\n";
	shrubfile << "       |o|        | |         | |" << "\n";
	shrubfile << "       |.|        | |         | |" << "\n";
	shrubfile << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << "\n";
	shrubfile.close();
	return (true);
}
