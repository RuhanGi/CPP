/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:43:58 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/15 21:20:09 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


// uses determinant calculation
Fixed calcArea(Point const a, Point const b, Point const c)
{
	Fixed det = Fixed((a.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat()));
	det = det - Fixed((a.getY().toFloat() - b.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat()));
	det = det / Fixed(2);
	return ((det < Fixed(0)) ? (Fixed(0) - det) : (det));
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	area1 = calcArea(point, b, c);
	Fixed	area2 = calcArea(a, point, c);
	Fixed	area3 = calcArea(a, b, point);

	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
		return (false);
	return (area1 + area2 + area3 <= calcArea(a, b, c));
}