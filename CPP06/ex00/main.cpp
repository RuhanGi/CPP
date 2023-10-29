/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:30:31 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/07 11:38:26 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "\x1B[31m" << "Enter One Argument!" << "\x1B[0m\n";
		return (1);
	}

	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception & e)
	{
		std::cerr << "\x1B[31m" << "Cannot Convert \"" << argv[1] << "\"!" << "\x1B[0m\n";
		return (1);
	}
	return (0);
}
