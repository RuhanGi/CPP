/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:01:43 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 16:08:49 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);

		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm &f );
		RobotomyRequestForm &operator=( const RobotomyRequestForm &f );
		~RobotomyRequestForm( void );
		
		bool	execute(Bureaucrat const & executor) const;
};
