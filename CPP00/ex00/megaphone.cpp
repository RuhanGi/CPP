/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:31:04 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/05 13:36:14 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 1)
		for (int i = 1; i < argc; i++)
			for (int j = 0; argv[i] && argv[i][j]; j++)
				std::cout << (char) toupper(argv[i][j]);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
}
