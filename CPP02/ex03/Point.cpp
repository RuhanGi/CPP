/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:43:52 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/15 21:28:30 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ):x(0), y(0)
{
	
}

Point::Point( const float x, const float y ):x(x), y(y)
{
	
}

Point::Point (const Point &p):x(p.getX()),y(p.getY())
{
	
}

// Since we can't assign const values, we cant assign x and y directly outside constructors
Point &Point::operator=(const Point &p)
{
	(void) p;
	return (*this);
}

Point::~Point( void )
{

}

const Fixed	&Point::getX( void ) const
{
	return (this->x);
}

const Fixed	&Point::getY( void ) const
{
	return (this->y);
}

std::ostream	&operator<<(std::ostream &out, const Point &p)
{
	out << "(" << p.getX() << ", " << p.getY() << ")";
	return (out);
}
