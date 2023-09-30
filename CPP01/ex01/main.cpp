/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:16:59 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/09 18:55:22 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 5;

    Zombie *head = zombieHorde(N, "Testers");
    for (int i = 0; i < N; i++)
        head[i].announce();
    delete[] head;
}
