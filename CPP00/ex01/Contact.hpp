/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:40:10 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/07 20:00:55 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string	phonenumber;
		std::string	secret;
	
	public:
		Contact(void);
		~Contact(void);

		std::string	getFirst(void);
		std::string	getLast(void);
		std::string	getNick(void);
		std::string	getNumber(void);
		std::string	getSecret(void);

		void	setFirst(std::string first);
		void	setLast(std::string last);
		void	setNick(std::string nick);
		void	setNumber(std::string num);
		void	setSecret(std::string secret);
		
		void	setAll(void);
};

#endif
