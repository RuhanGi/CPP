/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:53:59 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/27 16:11:59 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	testSpanWith(unsigned int n)
{
	std::cout << GREEN "|-------------------------------------------------|" RESET "\n";
	
	std::srand(time(NULL));

	Span				sp = Span(n);
	std::vector<int>	nums;
	nums.reserve(n);

	for (unsigned int i = 0; i < n; i++)
		nums.push_back(MIN + std::rand() % (MAX - MIN + 1));
	
	sp.addNumber(nums.begin(), nums.end());
	// sp.addNumber(nums.cbegin(), nums.cend());
	// sp.addNumber(nums.rbegin(), nums.rend());
	// sp.addNumber(nums.crbegin(), nums.crend());

	std::cout << CYAN " Shortest Span for " << n << " Numbers is: " PURPLE << sp.shortestSpan() << RESET "\n";
	std::cout << BLUE " Longest  Span for " << n << " Numbers is: " YELLOW << sp.longestSpan()  << RESET "\n";
}

int	main(void)
{
	// Span sp = Span(5);

	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);

	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	try
	{
		testSpanWith(10);
		testSpanWith(1000);
		testSpanWith(10000);
		testSpanWith(50000);
		testSpanWith(100000);
		testSpanWith(500000);
		// testSpanWith(1000000);
		// testSpanWith(5000000);
		// testSpanWith(10000000);
		std::cout << GREEN "|-------------------------------------------------|" RESET "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET "\n";
		return (1);
	}
	return 0;
}
