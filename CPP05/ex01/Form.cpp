/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:48:13 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 12:48:06 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const & n, int signg, int execg) : name(n), signgrade(signg), execgrade(execg)
{
	std::cout << "\x1B[33m" << "Form constructor called" << "\x1B[0m\n";
	this->issigned = false;
	if (signg < 1 || execg < 1)
		throw (Form::GradeTooHighException());
	if (signg > 150 || execg > 150)
		throw (Form::GradeTooLowException());
}

Form::Form( void ) : name("Default"), signgrade(100), execgrade(50)
{
	std::cout << "\x1B[33m" << "Default Form constructor called" << "\x1B[0m\n";
	this->issigned = false;
}

Form::Form( const Form &f ) : name(f.getName()), signgrade(f.getSignGrade()), execgrade(f.getExecGrade())
{
	std::cout << "\x1B[33m" << "Copy Form constructor called" << "\x1B[0m\n";
	*this = f;
}

Form &Form::operator=( const Form &f )
{
	std::cout << "\x1B[33m" << "Copy Form assignment operator called" << "\x1B[0m\n";
	this->issigned = f.getSignStatus();
	return (*this);
}

Form::~Form( void )
{
	std::cout << "\x1B[33m" << "Form Destructor called" << "\x1B[0m\n";
}

std::string const & Form::getName( void ) const
{
	return (this->name);
}

bool Form::getSignStatus( void ) const
{
	return (this->issigned);
}

int Form::getSignGrade( void ) const
{
	return (this->signgrade);
}

int Form::getExecGrade( void ) const
{
	return (this->execgrade);
}

bool	Form::beSigned(Bureaucrat brct)
{
	if (brct.getGrade() <= getSignGrade())
		this->issigned = true;
	else
		throw (Form::GradeTooLowException());
	return (getSignStatus());
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade set too Low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade set too High!");
}

std::ostream	&operator<<(std::ostream &out, const Form &f)
{
	out << "\x1B[32m" << "Form " << f.getName();
	if (f.getSignStatus())
		out << " (signed)";
	else
		out << " (unsigned)";
	out << ".\x1B[0m"; 
	return (out);
}
