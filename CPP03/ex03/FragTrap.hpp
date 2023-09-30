/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:12:01 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 11:32:26 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:

	public:
		FragTrap( void );
		FragTrap(const FragTrap &f);
		FragTrap &operator=(const FragTrap &f);
		~FragTrap( void );

		FragTrap(std::string name);

		void attack(const std::string& target);
		void highFivesGuys(void);
		
		static const unsigned int hp = 100;
		static const unsigned int ep = 100;
		static const int ad = 30;
};

#endif

