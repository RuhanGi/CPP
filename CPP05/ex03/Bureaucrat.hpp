/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:00:09 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 13:36:00 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{	
	private:
		std::string const	name;
		int					grade;
		int					setGrade(int grade);

	public:
		Bureaucrat(std::string const & n, int grade);

		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &f );
		Bureaucrat &operator=( const Bureaucrat &f );
		~Bureaucrat( void );

		std::string const & getName() const;
		int const &getGrade() const;

		void	increment( void );
		void	decrement( void );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void	signForm(AForm *f);
		void	executeForm(AForm const & form);
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &f);

