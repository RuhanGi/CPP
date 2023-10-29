/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:30:01 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/07 12:22:20 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::c = 0;
int ScalarConverter::i = 0;
float ScalarConverter::f = 0;
double ScalarConverter::d = 0;

ScalarConverter::ScalarConverter( void )
{
	// std::cout << "\x1B[33m" << "Default ScalarConverter constructor called" << "\x1B[0m\n";
}

ScalarConverter::ScalarConverter( const ScalarConverter &f )
{
	// std::cout << "\x1B[33m" << "Copy ScalarConverter constructor called" << "\x1B[0m\n";
	(void) f;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &f )
{
	// std::cout << "\x1B[33m" << "Copy ScalarConverter assignment operator called" << "\x1B[0m\n";
	(void) f;
	return (*this);
}

ScalarConverter::~ScalarConverter( void )
{
	// std::cout << "\x1B[33m" << "ScalarConverter Destructor called" << "\x1B[0m\n";
}

int	ScalarConverter::indexIn(std::string str)
{
	std::string	literals[10] = {"-inf", "-inff", "+inf", "+inff", "inf", "inff", "nan", "nanf", "-nan", "+nan"};

	for (unsigned long i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	for (int i = 0; i < 10; i++)
		if (str.compare(0, literals[i].length(), literals[i]) == 0)
			return (i);
	return (-1);
}

int	ScalarConverter::pseudo(std::string str)
{
	int	index = indexIn(str);
	if (index == -1)
		return (0);
	std::cout << "char   : impossible" << "\n";
	std::cout << "int    : impossible" << "\n";
	if (index == 0 || index == 1)
	{
		std::cout << "float  : -inff" << "\n";
		std::cout << "double : -inf" << "\n";
	}
	else if (2 <= index && index <= 5)
	{
		std::cout << "float  : inff" << "\n";
		std::cout << "double : inf" << "\n";
	}
	else
	{
		std::cout << "float  : nanf" << "\n";
		std::cout << "double : nan" << "\n";
	}
	return (1);
}

void	ScalarConverter::printChar()
{
	ScalarConverter::c = static_cast<char>(ScalarConverter::d);

	std::cout << "char   : ";
	if (ScalarConverter::d < -128 || ScalarConverter::d > 127)
		std::cout << "impossible";
	else if (ScalarConverter::d < ' ' || ScalarConverter::d > '~')
		std::cout << "Non displayable";
	else
		std::cout << "'" << ScalarConverter::c << "'";
	std::cout << "\n";
}

void	ScalarConverter::printInt()
{
	ScalarConverter::i = static_cast<int>(ScalarConverter::d);

	std::cout << "int    : ";
	if (ScalarConverter::d < INT_MIN || ScalarConverter::d > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << ScalarConverter::i;
	std::cout << "\n";
}

void	ScalarConverter::printDecimal()
{
	ScalarConverter::f = static_cast<float>(ScalarConverter::d);
	if ((ScalarConverter::d - static_cast<int>(ScalarConverter::d) == 0) 
		&& (-1000000 < ScalarConverter::d && ScalarConverter::d < 1000000))
	{
		std::cout << "float  : " << ScalarConverter::f << ".0f\n";
		std::cout << "double : " << ScalarConverter::d << ".0\n";
	}
	else
	{
		std::cout << "float  : " << ScalarConverter::f << "f\n";
		std::cout << "double : " << ScalarConverter::d << "\n";
	}
}

// explicitly converts to char else number
void	ScalarConverter::setVals(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		ScalarConverter::d = static_cast<double>(str[0]);
	else
		ScalarConverter::d = std::stod(str);
}

void	ScalarConverter::convert(std::string str)
{
	if (pseudo(str))
		return ;
	setVals(str);
	printChar();
	printInt();
	printDecimal();
}
