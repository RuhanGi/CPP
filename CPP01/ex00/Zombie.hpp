/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:15:10 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/09 17:43:30 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie( std::string n);
        Zombie( void );
        ~Zombie( void );

        std::string getName( void );
        void    setName( std::string n );

        void announce( void );
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif
