/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:11:36 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/27 14:57:21 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

#define GREY	"\x1B[30m"
#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define PURPLE	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define RESET	"\x1B[0m"

#define SIZE 100
#define FIND 5

class NotFound : public std::exception
{
	public:
		virtual const char *what() const throw();
};

const char *NotFound::what() const throw()
{
	return ("Integer Not Found in Container!");
}

template <typename T>
int	easyfind(T container, int find)
{
	if (std::find(container.begin(), container.end(), find) == container.end())
		throw NotFound();
	return (*std::find(container.begin(), container.end(), find));
}
