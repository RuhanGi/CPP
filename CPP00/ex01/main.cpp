/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:42:01 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/08 18:00:06 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string command;

	while (command.compare("EXIT") != 0)
	{
		std::cout << "\x1B[34mEnter Command (ADD, SEARCH, EXIT): \x1B[32m";
		std::getline(std::cin, command);
		std::cout << "\x1B[97m\n";
		if (command.compare("ADD") == 0)
			book.add();
		else if (command.compare("SEARCH") == 0)
			book.search();
		else if (command.compare("") == 0)
			continue;
		else if (command.compare("EXIT") != 0)
			std::cout << "\x1B[31mInvalid Command!\x1B[97m\n\n";
	}
	return (0);
}

// int main(void)
// {
// 	PhoneBook book;
// 	std::string command;

// 	std::cout << "\x1B[34mEnter Command (ADD, SEARCH, EXIT): \x1B[32m";
// 	std::cin >> command;
// 	std::cout << "\x1B[97m\n";
// 	while (command.compare("EXIT") != 0)
// 	{
// 		if (command.compare("ADD") == 0)
// 			book.add();
// 		else if (command.compare("SEARCH") == 0)
// 			book.search();
// 		else
// 			std::cout << "\x1B[31mInvalid Command!\x1B[97m\n\n";
// 		std::cout << "\x1B[34mEnter Command (ADD, SEARCH, EXIT): \x1B[32m";
// 		std::cin >> command;
// 		std::cout << "\x1B[97m\n";
// 	}
// 	return (0);
// }
