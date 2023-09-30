/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:08:54 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/08 18:06:13 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	
}

Contact::~Contact(void)
{
	
}

std::string	Contact::getFirst(void)
{
	return (this->firstname);
}

std::string	Contact::getLast(void)
{
	return (this->lastname);
}

std::string	Contact::getNick(void)
{
	return (this->nickname);
}

std::string	Contact::getNumber(void)
{
	return (this->phonenumber);
}

std::string	Contact::getSecret(void)
{
	return (this->secret);
}

void	Contact::setFirst(std::string first)
{
	this->firstname = first;
}

void	Contact::setLast(std::string last)
{
	this->lastname = last;
}

void	Contact::setNick(std::string nick)
{
	this->nickname = nick;
}

void	Contact::setNumber(std::string num)
{
	this->phonenumber = num;
}

void	Contact::setSecret(std::string secret)
{
	this->secret = secret;
}

void	Contact::setAll(void)
{
	std::string temp;

	do {
		std::cout << "First Name: ";
		std::getline(std::cin, temp);
	} while (!temp.compare(""));
	setFirst(temp);
	do {
		std::cout << "Last Name: ";
		std::getline(std::cin, temp);
	} while (!temp.compare(""));
	setLast(temp);
	do {
		std::cout << "Nickname: ";
		std::getline(std::cin, temp);
	} while (!temp.compare(""));
	setNick(temp);
	do {
		std::cout << "Phone Number: ";	
		std::getline(std::cin, temp);
	} while (!temp.compare(""));
	setNumber(temp);
	do {
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, temp);
	} while (!temp.compare(""));
	setSecret(temp);
}