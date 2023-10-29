/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:53:59 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/27 17:40:32 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	subjectTest()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << PURPLE "Top  Value: " CYAN << mstack.top() << std::endl;

	mstack.pop();

	std::cout << PURPLE "Size Value: " CYAN << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << YELLOW;
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << ", ";
	}
	std::cout << RESET "\n";
	std::stack<int> s(mstack);
}

void	subjectTestList()
{
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << PURPLE "Back Value: " CYAN  << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << PURPLE "Size Value: " CYAN << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << YELLOW;
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << ", ";
	}
	std::cout << RESET "\n";
	std::list<int> s(mstack);
}

void	myTests(unsigned int n)
{
	std::srand(time(NULL));

	MutantStack<int>	nums;

	for (unsigned int i = 0; i < n; i++)
		nums.push(MIN + std::rand() % (MAX - MIN + 1));
	
	std::cout << PURPLE "Size Value: " CYAN << nums.size() << std::endl;

	MutantStack<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		std::cout << YELLOW << *(it++);
		if (it != nums.end())
			std::cout << ", ";
	}
	std::cout << RESET "\n";

	MutantStack<int>::const_iterator cit = nums.cbegin();
	while (cit != nums.cend())
	{
		std::cout << GREY << *(cit++);
		if (cit != nums.cend())
			std::cout << ", ";
	}
	std::cout << RESET "\n";

	MutantStack<int>::reverse_iterator rit = nums.rbegin();
	while (rit != nums.rend())
	{
		std::cout << YELLOW << *(rit++);
		if (rit != nums.rend())
			std::cout << ", ";
	}
	std::cout << RESET "\n";

	MutantStack<int>::const_reverse_iterator crit = nums.crbegin();
	while (crit != nums.crend())
	{
		std::cout << GREY << *(crit++);
		if (crit != nums.crend())
			std::cout << ", ";
	}
	std::cout << RESET "\n";
}

int	main(void)
{
	std::cout << GREEN "|--------------------------------------------------------|" RESET "\n";
	subjectTest();
	std::cout << GREEN "|--------------------------------------------------------|" RESET "\n";
	subjectTestList();
	std::cout << GREEN "|--------------------------------------------------------|" RESET "\n";
	myTests(SIZE);
	std::cout << GREEN "|--------------------------------------------------------|" RESET "\n";

	return 0;
}
