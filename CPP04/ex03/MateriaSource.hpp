/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:07:51 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/25 14:12:53 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*inv[4];

	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource &f );
		MateriaSource &operator=( const MateriaSource &f );
		~MateriaSource( void );

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
