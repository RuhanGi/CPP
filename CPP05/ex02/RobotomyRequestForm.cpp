/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:01:33 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 16:05:49 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "\x1B[33m" << "RobotomyRequestForm constructor called" << "\x1B[0m\n";
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "\x1B[33m" << "Default RobotomyRequestForm constructor called" << "\x1B[0m\n";
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &f ) : AForm(f.getName(), f.getSignGrade(), f.getExecGrade())
{
	std::cout << "\x1B[33m" << "Copy RobotomyRequestForm constructor called" << "\x1B[0m\n";
	*this = f;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &f )
{
	std::cout << "\x1B[33m" << "Copy RobotomyRequestForm assignment operator called" << "\x1B[0m\n";
	setSigned(f.getSignStatus());
	setTarget(f.getTarget());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "\x1B[33m" << "RobotomyRequestForm Destructor called" << "\x1B[0m\n";
}

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		return (false);
	std::cout << "\x1B[32m" << "* drilling noises *\n";
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully!";
	else
		std::cout << "Robotomy attempt on " << getTarget() << " failed!";
	std::cout << "\x1B[0m\n";
	return (true);
}
