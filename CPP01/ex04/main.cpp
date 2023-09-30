/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:48:44 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 20:02:00 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	handleOutput(std::string text, char *argv[])
{
	std::ofstream	outfile;
	std::string		s1;
	std::string		s2;

	outfile.open((std::string)argv[1] + ".replace");
	if (outfile.fail())
	{
		std::cout << "\x1B[31mUnable to Create File!\x1B[97m\n";
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	for (int i = 0; i < (int) text.length(); i++)
		if (text.substr(i, s1.length()) == s1)
		{
			text = text.substr(0, i) + s2 + text.substr(i + s1.length());
			i += s2.length() - 1;
		}
	outfile << text;
	outfile.close();
	return (0);
}

int	main(int argc, char *argv[])
{
	std::ifstream infile;
	std::stringstream buffer;
	std::string text;

	if (argc != 4)
	{
		std::cout << "\x1B[31mIncorrect Number of Parameters!\x1B[97m\n";
		return (1);
	}
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "\x1B[31m\"" << argv[1] << "\" Failed to Open!\x1B[97m\n";
		return (1);
	}
	buffer << infile.rdbuf();
	text = buffer.str();
	return (handleOutput(text, argv));
}
