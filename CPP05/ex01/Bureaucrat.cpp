/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:00:13 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 12:20:11 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & n, int grade) : name(n)
{
	std::cout << "\x1B[33m" << "Bureaucrat constructor called" << "\x1B[0m\n";
	setGrade(grade);
}

Bureaucrat::Bureaucrat( void ) : name("Default")
{
	std::cout << "\x1B[33m" << "Default Bureaucrat constructor called" << "\x1B[0m\n";
	setGrade(150);
}

Bureaucrat::Bureaucrat( const Bureaucrat &f ) : name(f.getName())
{
	std::cout << "\x1B[33m" << "Copy Bureaucrat constructor called" << "\x1B[0m\n";
	*this = f;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &f )
{
	std::cout << "\x1B[33m" << "Copy Bureaucrat assignment operator called" << "\x1B[0m\n";
	setGrade(f.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "\x1B[33m" << "Bureaucrat Destructor called" << "\x1B[0m\n";
}

int	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
	return (this->grade);
}

std::string const & Bureaucrat::getName() const
{
	return (this->name);
}

int const &Bureaucrat::getGrade() const
{
	if (this->grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	return (this->grade);
}

void	Bureaucrat::increment( void )
{
	setGrade(getGrade() - 1);
}

void	Bureaucrat::decrement( void )
{
	setGrade(getGrade() + 1);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade set too Low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade set too High!");
}

void	Bureaucrat::signForm(Form *f)
{
	if (f->beSigned(*this))
		std::cout << "\x1B[32m" << getName() << " signed " << f->getName() << ".\x1B[0m\n";
	else
	{
		std::cout << "\x1B[31m" << getName() << " couldnt sign " << f->getName();
		std::cout << " because Grade is Too Low." << "\x1B[0m\n";
	}
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &f)
{
	out << "\x1B[32m" << f.getName() << ", bureaucrat grade " << f.getGrade() << ".\x1B[0m\n";
	return (out);
}
