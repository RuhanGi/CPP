/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:01:17 by mgoltay           #+#    #+#             */
/*   Updated: 2023/09/22 18:36:40 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain {
	private:
		std::string	*ideas;

	public:
		Brain( void );
		Brain( const Brain &f );
		Brain &operator=( const Brain &f );
		~Brain( void );

		std::string *getIdeas( void );
};
