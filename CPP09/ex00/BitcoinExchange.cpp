/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:04:28 by mgoltay           #+#    #+#             */
/*   Updated: 2023/11/02 21:16:49 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

unsigned int date_to_int(t_date date)
{
	return (100 * 100 * date.year + 100 * date.month + date.day);
}

t_date	int_to_date(unsigned int seed)
{
	t_date	date;

	date.year = seed / (100 * 100);
	date.month = seed / 100 - date.year * 100;
	date.day = seed - date.year * 100 * 100 - date.month * 100;
	return (date);
}

unsigned int	BitcoinExchange::parseDate( std::string str )
{
	if (str.size() > 15)
		throw BitcoinExchange::Invalid("Invalid Date!");
	int	dashcount = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '-')
			throw BitcoinExchange::Invalid("Invalid Date!");
		if (str[i] == '-' && ++dashcount && (i == 0 || !std::isdigit(str[i - 1]) || !std::isdigit(str[i + 1])))
			throw BitcoinExchange::Invalid("Invalid Date!");
	}
	if (dashcount != 2)
		throw BitcoinExchange::Invalid("Invalid Date!");

	t_date	date;
	date.year = 0;
	date.month = 0;
	date.day = 0;

	int	index = -1;
	while (str[++index] != '-')
		date.year = date.year * 10 + (str[index] - '0');
	while (str[++index] != '-')
		date.month = date.month * 10 + (str[index] - '0');
	while (++index < (int) str.size())
		date.day = date.day * 10 + (str[index] - '0');

	if (date.month == 0 || date.month > 12 || date.day == 0 || date.day > 31)
		throw BitcoinExchange::Invalid("Invalid Date!");
	if (date.month == 2 && date.day > (28 + (date.year % 4 == 0)))
		throw BitcoinExchange::Invalid("Invalid Date!");
	if (date.day == 31 && (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11))
		throw BitcoinExchange::Invalid("Invalid Date!");
	return (date_to_int(date));
}

float	BitcoinExchange::parseValue( std::string str )
{
	int	pointcount = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.' && !(i == 0 && str[i] == '-'))
			throw BitcoinExchange::Invalid("Invalid Value!");
		if (str[i] == '.' && ++pointcount && i == 0)
			throw BitcoinExchange::Invalid("Invalid Value!");
	}
	if (pointcount > 1)
		throw BitcoinExchange::Invalid("Invalid Value!");

	return (static_cast<float>(atof(str.c_str())));
}

void	BitcoinExchange::fillHistory( void )
{
	std::string		line;
	std::ifstream	fil(DATA_FILE);
	size_t			pos;

	if (!fil.is_open())
		throw BitcoinExchange::Invalid("Invalid Data File!");

	while (getline(fil, line))
	{
		if (line == "date,exchange_rate" || line == "")
			continue ;
		pos = line.find_first_of(',');
		this->history[parseDate(line.substr(0, pos))] = parseValue(line.substr(pos+ 1));
	}
}

bool	BitcoinExchange::isMinDate(unsigned int date)
{
	for (std::map<unsigned int, float>::iterator it = this->history.begin(); it != this->history.end(); it++)
		if (it->first <= date)
			return (false);
	return (true);
}

float	BitcoinExchange::getValue(unsigned int date)
{
	std::map<unsigned int, float>::iterator	closest = this->history.begin();
	for (std::map<unsigned int, float>::iterator it = this->history.begin(); it != this->history.end(); it++)
		if (it->first <= date && it->first > closest->first)
			closest = it;
	return (closest->second);
}

void	BitcoinExchange::handleLine( std::string str )
{
	if (str == "date | value" || str == "")
		return ;
	
	size_t	pos = str.find_first_of(" | ");
	if (pos == std::string::npos || pos + 3 >= str.size())
		throw BitcoinExchange::Invalid("Invalid Line!");

	unsigned int	date = parseDate(str.substr(0, pos));
	float			amount = parseValue(str.substr(pos + 3));

	if (amount < 0)
		throw BitcoinExchange::Invalid("Negative Amount!");
	if (amount > 1000)
		throw BitcoinExchange::Invalid("Too Large of an Amount!");
	if (this->history.size() == 0 || isMinDate(date))
		throw BitcoinExchange::Invalid("Not Enough Data!");

	std::cout << GREEN "Value of " YELLOW << amount << GREEN "\t bitcoins on " << CYAN;
	std::cout << str.substr(0, pos) << GREEN " = " PURPLE << amount * getValue(date) << RESET "\n";
}

BitcoinExchange::BitcoinExchange( std::string filename )
{
	fillHistory();

	std::string		line;
	std::ifstream	fil(filename.c_str());

	if (!fil.is_open())
		throw BitcoinExchange::Invalid("Invalid Data File!");

	std::cout << BLUE << "Value of X\t bitcoins on YYYY-MM-DD = ANS" << RESET "\n";
	std::cout << BLUE << "------------------------------------------------" << RESET "\n";
	while (getline(fil, line))
	{
		try
		{
			handleLine(line);
		}
		catch (std::exception & e)
		{
			std::cerr << GREY "ERROR: " << e.what() << RESET "\n";
		}
	}
}

BitcoinExchange::BitcoinExchange( void )
{
	
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &f )
{
	*this = f;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &f )
{
	(void) f;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void ) 
{
	
}

BitcoinExchange::Invalid::Invalid(const char *msg) : _msg(msg)
{
	
}

const char *BitcoinExchange::Invalid::what() const throw()
{
	return (this->_msg);
}
