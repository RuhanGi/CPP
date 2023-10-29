/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:53:59 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/27 14:18:37 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
void	fillInt(T &container)
{
	for (int i = 0; i < SIZE; i++)
		container.push_back(i);
}

void    testArray()
{
	std::array<int, SIZE> arr;
	for (int i = 0; i < SIZE; i++)
		arr[i] = i;
	
	int found = easyfind(arr, FIND);
	std::cout << GREEN "Integer found in Array [" << found << "]" RESET "\n";
}

void    testVector()
{
	std::vector<int> vec;
	fillInt(vec);
	
	int found = easyfind(vec, FIND);
	std::cout << YELLOW "Integer found in Vector [" << found << "]" RESET "\n";
}

void    testDeque()
{
	std::deque<int> deq;
	fillInt(deq);
	
	int found = easyfind(deq, FIND);
	std::cout << BLUE "Integer found in Deque [" << found << "]" RESET "\n";
}

void    testForward_list()
{
	std::forward_list<int> flst;

	for (int i = SIZE - 1; i >= 0; i--)
		flst.push_front(i);
	
	int found = easyfind(flst, FIND);
	std::cout << PURPLE "Integer found in Forward_List [" << found << "]" RESET "\n";
}

void    testList()
{
	std::list<int> lst;
	fillInt(lst);
	
	int found = easyfind(lst, FIND);
	std::cout << CYAN "Integer found in List [" << found << "]" RESET "\n";
}

int	main(void)
{
	try
	{
		testArray();
		testVector();
		testDeque();
		testForward_list();
		testList();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET "\n";
		return (1);
	}
	return (0);
}
