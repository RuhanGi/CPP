/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:04:27 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/23 18:49:47 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	multiply(int &a)
{
	a = a * 5;
}

template <typename T>
void	print(T &n)
{
	std::cout << YELLOW "Instance: " GREEN << n << RESET "\n";
}

int main( void ) {	
	int a[SIZE];

	for (int i = 0; i < SIZE; i++)
		a[i] = i;

	// ::iter(a, SIZE, print);
	::iter(a, SIZE, multiply);
	::iter(a, SIZE, print);

	std::string strs[SIZE];
	// ::iter(strs, SIZE, print);
	for (int i = 0; i < SIZE; i++)
		strs[i] = "Test - " + ((std::string) "abcdefghij").substr(i);
	::iter(strs, SIZE, print);

	return 0;
}
