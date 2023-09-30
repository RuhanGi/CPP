/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:29 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/15 19:12:08 by mgoltay          ###   ########.fr       */
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

		bool	operator >  (const Fixed &f);
		bool	operator <  (const Fixed &f);
		bool	operator >= (const Fixed &f);
		bool	operator <= (const Fixed &f);
		bool	operator == (const Fixed &f);
		bool	operator != (const Fixed &f);
	
		Fixed	operator +  (const Fixed &f);
		Fixed	operator -  (const Fixed &f);
		Fixed	operator *  (const Fixed &f);
		Fixed	operator /  (const Fixed &f);
	
		Fixed	operator ++ ( void );
		Fixed	operator ++ ( int );
		Fixed	operator -- ( void );
		Fixed	operator -- ( int );

		static Fixed	&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);


#endif
