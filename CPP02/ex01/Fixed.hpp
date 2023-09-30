/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:29 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/15 17:51:28 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		static const int bits;

	public:
		Fixed( void );
		Fixed( const int d );
		Fixed( const float f );
		Fixed (const Fixed& f);
		Fixed &operator=(const Fixed &f);
		~Fixed( void );
	
		int getRawBits( void ) const;
		void    setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);

#endif
