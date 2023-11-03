/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:23:38 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/29 12:28:39 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 2 || !argv)
		return (std::cerr << RED "Requires Arguments!" RESET "\n", 1);

	try
	{
		PmergeMe(&argv[1], argc - 1);
	}
	catch (std::exception & e)
	{
		std::cerr << RED "ERROR: " << e.what() << RESET "\n";
		return (1);
	}

	return (0);
}
