/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:52:00 by tohma             #+#    #+#             */
/*   Updated: 2024/04/23 23:05:13 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
};

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}
