/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:04:02 by mgoltay           #+#    #+#             */
/*   Updated: 2023/11/01 18:32:50 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2 || !argv)
		return (std::cerr << RED "Input One Argument!" RESET "\n", 1);

	try
	{
		BitcoinExchange btc(argv[1]);
	}
	catch (std::exception & e)
	{
		std::cerr << RED "ERROR: " << e.what() << RESET "\n";
		return (1);
	}

	return (0);
}
