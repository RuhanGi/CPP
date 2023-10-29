/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:29:56 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/07 11:05:15 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <climits>

class ScalarConverter
{
	private:
		static char		c;
		static int		i;
		static float	f;
		static double	d;

	public:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &f );
		ScalarConverter &operator=( const ScalarConverter &f );
		virtual ~ScalarConverter( void );

		static int	indexIn(std::string str);
		static int	pseudo(std::string str);
		static void	printChar();
		static void	printInt();
		static void	printDecimal();
		static void	setVals(std::string str);
		static void	convert(std::string str);
};
