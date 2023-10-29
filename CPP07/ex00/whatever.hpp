/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:04:33 by mgoltay           #+#    #+#             */
/*   Updated: 2023/10/23 18:17:02 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	&min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	&max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}
