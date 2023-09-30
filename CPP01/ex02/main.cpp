/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:57:45 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/09 19:14:53 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Memory address of 'string'   : " << &string << "\n";
    std::cout << "Memory address of 'stringPTR': " << &stringPTR << "\n";
    std::cout << "Memory address of 'stringREF': " << &stringREF << "\n";

    std::cout << "Value of 'string'   : " << string << "\n";
    std::cout << "Value of 'stringPTR': " << stringPTR << "\n";
    std::cout << "Value of 'stringREF': " << stringREF << "\n";
}
