/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:01:49 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 16:04:08 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "\x1B[33m" << "PresidentialPardonForm constructor called" << "\x1B[0m\n";
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "\x1B[33m" << "Default PresidentialPardonForm constructor called" << "\x1B[0m\n";
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &f ) : AForm(f.getName(), f.getSignGrade(), f.getExecGrade())
{
	std::cout << "\x1B[33m" << "Copy PresidentialPardonForm constructor called" << "\x1B[0m\n";
	*this = f;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &f )
{
	std::cout << "\x1B[33m" << "Copy PresidentialPardonForm assignment operator called" << "\x1B[0m\n";
	setSigned(f.getSignStatus());
	setTarget(f.getTarget());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "\x1B[33m" << "PresidentialPardonForm Destructor called" << "\x1B[0m\n";
}

bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		return (false);
	std::cout << "\x1B[32m" << getTarget() << " has been pardoned by Zaphod Beeblebrox." << "\x1B[0m\n";
	return (true);
}
