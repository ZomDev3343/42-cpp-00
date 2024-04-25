/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:14:56 by truello           #+#    #+#             */
/*   Updated: 2024/04/25 16:45:53 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_last_contact_id = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact(void)
{
	Contact	contact;
	std::string	line;
	while (line.empty())
	{
		std::cout << "Entrez le prenom : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact.set_first_name(line);
	while (line.empty())
	{
		std::cout << "Entrez le nom : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact.set_last_name(line);
	while (line.empty())
	{
		std::cout << "Entrez le surnom : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact.set_nickname(line);
	while (line.empty())
	{
		std::cout << "Entrez le numero de telephone : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact.set_phone_number(line);
	while (line.empty())
	{
		std::cout << "Entrez votre plus grand secret : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact.set_darkest_secret(line);
	contact.set_empty(false);
	_contacts[_last_contact_id] = contact;
	if(++_last_contact_id > 7)
		_last_contact_id = 0;
}

static void	print_field(const std::string &field)
{
	int space_nb;
	int	max_len;

	max_len = field.length() < 10 ? field.length() : 10;
	space_nb = 10 - max_len;
	for (int i = 0; i < space_nb; i++)
		std::cout << " ";
	for (int i = 0; i < max_len - space_nb; i++)
	{
		if (max_len == 10 && i == max_len - space_nb - 1)
			std::cout << ".";
		else
			std::cout << field[i];
	}
}

void	PhoneBook::_print_contacts(void)
{
	for (int i = 0; i < 8; i++)
	{
		Contact contact = _contacts[i];
		if (!contact.is_empty())
		{
			print_field(contact.first_name());
			std::cout << " | ";
			print_field(contact.last_name());
			std::cout << " | ";
			print_field(contact.nickname());
			std::cout << " | ";
			print_field(contact.phone_number());
			std::cout << " | ";
			print_field(contact.darkest_secret());
			std::cout << std::endl;
		}
	}
}

void PhoneBook::search_contact(void)
{

}
