/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:50:21 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/05 15:38:34 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define SIZE 8

class PhoneBook {
	private:
		Contact contacts[SIZE];
		int		index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		getIndex(void);
		void	setIndex(int num);
		void	add(void);
		void	display(int i);
		void	search(void);
};

#endif
