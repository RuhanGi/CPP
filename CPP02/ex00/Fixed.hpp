/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:42:29 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/12 20:10:08 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		static const int bits;

	public:
		Fixed( void );
		Fixed (Fixed& f);
		Fixed &operator=(Fixed &f);
		~Fixed( void );
	
		int getRawBits( void ) const;
		void    setRawBits( int const raw );
};

#endif
