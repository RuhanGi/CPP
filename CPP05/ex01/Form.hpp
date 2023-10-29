/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:48:09 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 12:19:03 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				issigned;
		const int			signgrade;
		const int			execgrade;

	public:
		Form(std::string const & n, int signg, int execg);

		Form( void );
		Form( const Form &f );
		Form &operator=( const Form &f );
		~Form( void );

		std::string const & getName( void ) const;
		bool getSignStatus( void ) const;
		int getSignGrade( void ) const;
		int getExecGrade( void ) const;

		bool	beSigned(Bureaucrat brct);

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
};

std::ostream	&operator<<(std::ostream &out, const Form &f);
