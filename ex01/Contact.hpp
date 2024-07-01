/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:52:59 by tohma             #+#    #+#             */
/*   Updated: 2024/05/16 13:52:49 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string.h>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		bool		_is_empty;

	public:
		Contact();
		~Contact();

		std::string first_name() const { return this->_first_name; }
		void set_first_name(std::string first_name) { this->_first_name = first_name; }

		std::string last_name() const { return this->_last_name; }
		void set_last_name(std::string last_name) { this->_last_name = last_name; }

		std::string nickname() const { return this->_nickname; }
		void set_nickname(std::string nickname) { this->_nickname = nickname; }

		std::string phone_number() const { return this->_phone_number; }
		void set_phone_number(std::string phone_number) { this->_phone_number = phone_number; }

		std::string darkest_secret() const { return this->_darkest_secret; }
		void set_darkest_secret(std::string darkest_secret) { this->_darkest_secret = darkest_secret; }

		bool	is_empty() const { return this->_is_empty; }
		void	set_empty(bool empty) { this->_is_empty = empty; }

};

#endif
