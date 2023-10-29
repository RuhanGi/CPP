/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:04:27 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/23 20:31:59 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template < template<class> class A, typename T>
void	iter(A<T> arr, int len, void (*f)(T &))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

void	multiply(int &a)
{
	a = a * 5;
}

template <typename T>
void	print(T &n)
{
	std::cout << YELLOW "Instance: " GREEN << n << RESET "\n";
}

int main( void )
{	
	try
	{
		Array<int> abc = Array<int>(SIZE);
		for (int i = 0; i < SIZE; i++)
			abc[i] = i * 5;
		::iter(abc, SIZE, multiply);
		::iter(abc, SIZE, print);
		// abc[5] = -1;
		Array<std::string> strs = Array<std::string>(5);
		for (int i = 0; i < SIZE; i++)
			strs[i] = "Test - " + ((std::string) "abcdefghij").substr(i);
		::iter(strs, SIZE, print);
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET "\n";
		return (1);
	}
	return 0;
}
