/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:22 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 18:10:59 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon {
	private:
		std::string	type;
	
	public:
		Weapon( std::string t );
		~Weapon( void );

		const std::string &getType( void );
		void	setType( std::string str );
};

#endif
