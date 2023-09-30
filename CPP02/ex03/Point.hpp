/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:43:44 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/15 20:41:19 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point( void );
		Point( const float x, const float y );
		Point (const Point& p);
		Point &operator=(const Point &p);
		~Point( void );
	
		const Fixed	&getX( void ) const;
		const Fixed	&getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream	&operator<<(std::ostream &out, const Point &p);

#endif
