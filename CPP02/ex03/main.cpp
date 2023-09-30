/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:41:55 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/16 17:54:21 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*

(0, 0)
|\ 
| \ 
|  \ 
|   \ 
|    \ (50,50)
|     \ 
|      \ 
|       \ 
_________\ 
(0,0)		(100,0)

*/

int main(void)
{
	Point p1 = Point(0, 0);
	Point p2 = Point(0, 100);
	Point p3 = Point(100, 0);

	std::cout << "Triangle Points:\n- " << p1 << "\n- " << p2 << "\n- " << p3;


	Point a = Point(49, 49);
	std::cout << "\n\n\x1B[32mIs Point " << a << " In?:\x1B[0m " << bsp(p1, p2, p3, a) << "\n";

	Point b = Point(50, 50);
	std::cout << "\n\n\x1B[32mIs Point " << b << " In?:\x1B[0m " << bsp(p1, p2, p3, b) << "\n";
	
	Point c = Point(51, 51);
	std::cout << "\n\n\x1B[32mIs Point " << c << " In?:\x1B[0m " << bsp(p1, p2, p3, c) << "\n";

	Point d = Point(1, 1);
	std::cout << "\n\n\x1B[32mIs Point " << d << " In?:\x1B[0m " << bsp(p1, p2, p3, d) << "\n";

	Point e = Point(-1, 50);
	std::cout << "\n\n\x1B[32mIs Point " << e << " In?:\x1B[0m " << bsp(p1, p2, p3, e) << "\n";

	Point f = Point(50, -1);
	std::cout << "\n\n\x1B[32mIs Point " << f << " In?:\x1B[0m " << bsp(p1, p2, p3, f) << "\n";

	std::cout << "\n";
}
