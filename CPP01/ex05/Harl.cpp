/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:04:13 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/10 20:30:29 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{

}

Harl::~Harl( void )
{
    
}
void Harl::debug( void )
{
    std::cout << "[DEBUG] ";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple";
    std::cout << "-pickle-specialketchup burger. I really do!\n";
}

void Harl::info( void )
{
    std::cout << "[INFO] ";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put ";
    std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning( void )
{
    std::cout << "[WARNING] ";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming";
    std::cout << " for years whereas you started working here since last month.\n";
}

void Harl::error( void )
{
    std::cout << "[ERROR] ";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level )
{
    void    (Harl::*fncptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string keys[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
        if (keys[i] == level)
            (this->*fncptr[i])();
}
