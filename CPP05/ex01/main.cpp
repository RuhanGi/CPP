/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:59:41 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/30 13:31:02 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat b = Bureaucrat("Burey", 50);
		Form f = Form("Papers", 125, 80);
		std::cout << b << f << "\n";
		b.signForm(&f);
		std::cout << b << f << "\n";
		Form execs = Form("HighLevel", 25, 10);
		b.signForm(&execs);
		std::cout << "Finished\n";
	}
	catch (std::exception & e)
	{
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m\n";
		return (1);
	}
	return (0);
}
