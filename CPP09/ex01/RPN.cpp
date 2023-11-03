/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:16:19 by mgoltay           #+#    #+#             */
/*   Updated: 2023/11/03 21:52:04 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void )
{
	
}

RPN::RPN( const RPN &f )
{
	*this = f;
}

RPN &RPN::operator=( const RPN &f )
{
	if (this == &f)
		return (*this);
	this->nums = f.nums;
	return (*this);
}

RPN::~RPN( void )
{

}

bool	RPN::isIn(char c, std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (c == str[i])
			return (1);
	return (0);
}

bool	RPN::checkValidity( std::string &eq )
{
	for (size_t i = 0; i < eq.size(); i++)
		if (std::isspace(eq[i]) && (i == 0 || i+1 == eq.size() || std::isspace(eq[i+1])))
				eq.erase(i--, 1);
	for (size_t i = 0; i < eq.size(); i++)
	{
		if (!isIn(eq[i], "0123456789+-/*") && !std::isspace(eq[i]))
			return (false);
		if (isIn(eq[i], "0123456789+-/*") && i+1 != eq.size() && !std::isspace(eq[i+1]))
			return (false);
	}
	return (!eq.empty());
}

void	RPN::operate(char c)
{
	if (this->nums.size() < 2)
		throw RPN::NotEnoughOperands();

	int rightoperand = this->nums.top();
	this->nums.pop();
	int leftoperand = this->nums.top();
	this->nums.pop();

	if (c == '+')
		this->nums.push(leftoperand + rightoperand);
	else if (c == '-')
		this->nums.push(leftoperand - rightoperand);
	else if (c == '*')
		this->nums.push(leftoperand * rightoperand);
	else if (c == '/' && rightoperand != 0)
		this->nums.push(leftoperand / rightoperand);
	else if (c == '/' && rightoperand == 0)
		throw RPN::ZeroDivision();

	// std::cout << GREY << leftoperand << c << rightoperand << " = " << this->nums.top() << RESET "\n";
}

RPN::RPN( std::string equation )
{
	if (!checkValidity(equation))
		throw RPN::InvalidFormat();
	for (size_t i = 0; i < equation.size(); i++)
		if (std::isspace(equation[i]))
				equation.erase(i--, 1);
	for (size_t i = 0; i < equation.size(); i++)
	{
		if (std::isdigit(equation[i]))
			this->nums.push(equation[i] - '0');
		else
			operate(equation[i]);
	}
	
	std::cout << GREEN << this->nums.top() << RESET "\n";
	
	if (this->nums.size() != 1)
		std::cout << GREY "Stack had More than One Element After Completion! (Answer May Not Satisfy)" RESET "\n";
}

const char *RPN::InvalidFormat::what() const throw()
{
	return ("Equation is in Invalid Format!");
}

const char *RPN::NotEnoughOperands::what() const throw()
{
	return ("Not Enough Operands!");
}

const char *RPN::ZeroDivision::what() const throw()
{
	return ("Dividing By Zero!");
}
