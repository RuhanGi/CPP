/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:16:22 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/29 14:11:10 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>

#define GREY	"\x1B[30m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define PURPLE	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define RESET	"\x1B[0m"

class RPN
{
	private:
		std::stack<int>	nums;

	public:
		RPN( void );
		RPN( const RPN &f );
		RPN &operator=( const RPN &f );
		~RPN( void );

		RPN( std::string equation );

		static bool	isIn(char c, std::string str);
		static bool	checkValidity( std::string &eq );
		void		operate(char c);

		class InvalidFormat : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughOperands : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class ZeroDivision : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
