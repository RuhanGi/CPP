/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:29:56 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/07 11:34:40 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdint>

struct	Data
{
	char		c;
	int			i;
	std::string	s;
};

class Serializer
{
	public:
		Serializer( void );
		Serializer( const Serializer &f );
		Serializer &operator=( const Serializer &f );
		virtual ~Serializer( void );

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
