/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:59:41 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 13:31:10 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a;
		Bureaucrat b = Bureaucrat("Burey", 1);
		Bureaucrat c = Bureaucrat("Wronged", 150);
		Bureaucrat d(c);
	
		b.decrement();
		d.increment();
	
		std::cout << a << b << c << d;
	}
	catch (std::exception & e)
	{
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m\n";
		return (1);
	}
	return (0);
}
