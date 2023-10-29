/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:48:13 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 12:48:06 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const & n, int signg, int execg) : name(n), signgrade(signg), execgrade(execg)
{
	std::cout << "\x1B[33m" << "AForm constructor called" << "\x1B[0m\n";
	if (signg < 1 || execg < 1)
		throw (AForm::GradeTooHighException());
	if (signg > 150 || execg > 150)
		throw (AForm::GradeTooLowException());
	this->issigned = false;
	this->target = "DefaultTarget";
}

AForm::AForm( void ) : name("Default"), signgrade(100), execgrade(50)
{
	std::cout << "\x1B[33m" << "Default AForm constructor called" << "\x1B[0m\n";
	this->issigned = false;
	this->target = "DefaultTarget";
}

AForm::AForm( const AForm &f ) : name(f.getName()), signgrade(f.getSignGrade()), execgrade(f.getExecGrade())
{
	std::cout << "\x1B[33m" << "Copy AForm constructor called" << "\x1B[0m\n";
	*this = f;
}

AForm &AForm::operator=( const AForm &f )
{
	std::cout << "\x1B[33m" << "Copy AForm assignment operator called" << "\x1B[0m\n";
	this->issigned = f.getSignStatus();
	this->target = f.getTarget();
	return (*this);
}

AForm::~AForm( void )
{
	std::cout << "\x1B[33m" << "AForm Destructor called" << "\x1B[0m\n";
}

std::string const & AForm::getName( void ) const
{
	return (this->name);
}

bool AForm::getSignStatus( void ) const
{
	return (this->issigned);
}

int AForm::getSignGrade( void ) const
{
	return (this->signgrade);
}

int AForm::getExecGrade( void ) const
{
	return (this->execgrade);
}

std::string AForm::getTarget( void ) const
{
	return (this->target);
}

void	AForm::setSigned(bool hasbeen)
{
	this->issigned = hasbeen;
}

void	AForm::setTarget(std::string target)
{
	this->target = target;
}

bool	AForm::beSigned(Bureaucrat brct)
{
	if (brct.getGrade() <= getSignGrade())
		this->issigned = true;
	else
	{
		std::cout << "\x1B[31m" << brct.getName() << " couldnt sign " << *this;
		std::cout << " because Bureaucrat Grade set too Low" << "\x1B[0m\n";
		throw (AForm::GradeTooLowException());
	}
	return (getSignStatus());
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade set too Low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade set too High!");
}

std::ostream	&operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName();
	if (f.getSignStatus())
		out << " (signed)";
	else
		out << " (unsigned)";
	return (out);
}
