/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:04:32 by mgoltay           #+#    #+#             */
/*   Updated: 2023/11/02 21:06:13 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <stdlib.h>

#define GREY	"\x1B[30m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define PURPLE	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define RESET	"\x1B[0m"

#define DATA_FILE "data.csv"

typedef struct s_date
{
	unsigned int	year;
	unsigned int	month;
	unsigned int	day;
} t_date;

class BitcoinExchange
{
	private:
		std::map<unsigned int, float>	history;

	public:
		BitcoinExchange( std::string filename );

		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &f );
		BitcoinExchange &operator=( const BitcoinExchange &f );
		~BitcoinExchange( void );

		unsigned int	parseDate( std::string str );
		float			parseValue( std::string str );
		void			fillHistory( void );
		void			handleLine( std::string str );
		bool			isMinDate(unsigned int date);
		float			getValue(unsigned int date);

		class Invalid : public std::exception
		{
			private:
				const char *_msg;

			public:
				Invalid(const char *msg);
				virtual const char *what() const throw();
		};
};
