/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:04:09 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 20:15:27 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl( void );
		~Harl( void );

		void complain( std::string level );
};

#endif
