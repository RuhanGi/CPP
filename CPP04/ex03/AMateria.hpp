/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:35:33 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/24 17:13:25 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class AMateria
{
	protected:
		const std::string	type;
		
	public:
		AMateria(std::string const & type);
		AMateria( void );
		AMateria( const AMateria &f );
		AMateria &operator=( const AMateria &f );
		virtual ~AMateria( void );
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
