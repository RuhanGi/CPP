/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:30:31 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/07 11:31:36 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data vals;
	vals.c = 'a';
	vals.i = 42;
	vals.s = "a";
	
	std::cout << "\x1B[32m" << "vals BEFORE" << "\x1B[0m\n";
	std::cout << "char   : '" << vals.c << "'\n";
	std::cout << "int    : " << vals.i << "\n";
	std::cout << "string : " << vals.s << "\n";

	Data *ptr = Serializer::deserialize(Serializer::serialize(&vals));
	ptr->c = 'b';
	ptr->i = 21;
	ptr->s = "b";

	std::cout << "\x1B[32m" << "\nvals AFTER" << "\x1B[0m\n";
	std::cout << "char   : '" << vals.c << "'\n";
	std::cout << "int    : " << vals.i << "\n";
	std::cout << "string : " << vals.s << "\n";

	return (0);
}
