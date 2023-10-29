/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:11:32 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 15:43:06 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &f );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &f );
		~ShrubberyCreationForm( void );
		
		bool	execute(Bureaucrat const & executor) const;
};
