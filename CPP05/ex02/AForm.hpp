/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm
{
	private:
		std::string const	name;
		bool				issigned;
		const int			signgrade;
		const int			execgrade;
		std::string			target;

	public:
		AForm(std::string const & n, int signg, int execg);

		AForm( void );
		AForm( const AForm &f );
		AForm &operator=( const AForm &f );
		virtual ~AForm( void );

		std::string const & getName( void ) const;
		bool getSignStatus( void ) const;
		int getSignGrade( void ) const;
		int getExecGrade( void ) const;
		std::string getTarget( void ) const;

		void	setSigned(bool hasbeen);
		void	setTarget(std::string target);

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

		virtual bool	execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &out, const AForm &f);
