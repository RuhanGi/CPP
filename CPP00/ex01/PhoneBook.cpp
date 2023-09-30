/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:08:59 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/08 18:03:04 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{

}

int		PhoneBook::getIndex(void)
{
	return (this->index);
}

void	PhoneBook::setIndex(int num)
{
	this->index = num;
}

void	PhoneBook::add(void)
{
	Contact temp;

	if (this->index < SIZE)
		contacts[this->index++].setAll();
	else
	{
		for (int i = 0; i < SIZE - 1; i++)
			contacts[i] = contacts[i + 1];
		contacts[SIZE - 1].setAll();
	}
	std::cout << "\n";
}

void	PhoneBook::display(int i)
{
	if (i <= 0 || i > this->index)
		std::cout << "\n\x1B[31mOut of Bounds Index!\x1B[97m\n";
	else
	{
		std::cout << "First Name: " << this->contacts[i - 1].getFirst() << "\n";
		std::cout << "Last Name: " << this->contacts[i - 1].getLast() << "\n";
		std::cout << "Nickname: " << this->contacts[i - 1].getNick() << "\n";
		std::cout << "Phone Number: " << this->contacts[i - 1].getNumber() << "\n";
		std::cout << "Darkest Secret: " << this->contacts[i - 1].getSecret() << "\n";
	}
}

void	outputTen(std::string str)
{
	int	len;

	len = str.length();
	if (len <= 10)
	{
		for (int i = 0; i < 10 - len; i++)
			std::cout << " ";
		std::cout << str;
	}
	else
		std::cout << str.substr(0, 9) << ".";
}

void	PhoneBook::search(void)
{
	std::string buffer;

	for (int i = 0; i < this->index; i++)
	{
		std::cout << "         " << (i + 1) << "|";
		outputTen(this->contacts[i].getFirst());
		std::cout << "|";
		outputTen(this->contacts[i].getLast());
		std::cout << "|";
		outputTen(this->contacts[i].getNick());
		std::cout << "\n";
	}
	if (this->index > 0)
	{
		std::cout << "\n\x1B[34mDisplay which entry: \x1B[32m";
		std::getline(std::cin, buffer);
		std::cout << "\x1B[97m";
		if (buffer.length() == 0)
			std::cout << "\n\x1B[31mNothing Entered!\x1B[97m\n";
		else if (buffer.length() != 1 || buffer.at(0) < '1' || buffer.at(0) > '8')
			std::cout << "\n\x1B[31mOut of Bounds Index!\x1B[97m\n";
		else
			display(buffer.at(0) - '0');
	}
	else
		std::cout << "\x1B[31mEmpty Phonebook!\x1B[97m\n";
	std::cout << "\n";
}
