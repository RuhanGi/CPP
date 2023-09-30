/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:04:04 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 20:50:27 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    callLevel(Harl h, int level)
{
	switch (level) {
		case 0:
			h.complain("DEBUG");
			std::cout << "\n";
		case 1:
			h.complain("INFO");
			std::cout << "\n";
		case 2:
			h.complain("WARNING");
			std::cout << "\n";
		case 3:
			h.complain("ERROR");
			std::cout << "\n";
	}
}

int main(int argc, char *argv[])
{
	Harl h;
	int i = -1;
	std::string keys[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (0);
	}
	while (++i < 4)
		if (keys[i] == (std::string)argv[1])
			break ;
	if (i == 4)
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	else
		callLevel(h, i);
	return (0);
}
