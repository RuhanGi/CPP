/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:12:01 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/07 22:14:26 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:

	public:
		FragTrap( void );
		FragTrap(const FragTrap &f);
		FragTrap &operator=(const FragTrap &f);
		virtual ~FragTrap( void );

		FragTrap(std::string name);

		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif

