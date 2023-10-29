/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:01:52 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 14:03:40 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);

		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm &f );
		PresidentialPardonForm &operator=( const PresidentialPardonForm &f );
		~PresidentialPardonForm( void );
		
		bool	execute(Bureaucrat const & executor) const;
};
