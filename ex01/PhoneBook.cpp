/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:14:56 by truello           #+#    #+#             */
/*   Updated: 2024/04/27 20:35:15 by tohma            ###   ########.fr       */
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
	Contact *contact = _contacts;
	std::string	line;
	while (line.empty() && !std::cin.eof())
	{
		std::cout << "Entrez le prenom : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact[_last_contact_id].set_first_name(line);
	line = std::string();
	while (line.empty() && !std::cin.eof())
	{
		std::cout << "Entrez le nom : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact[_last_contact_id].set_last_name(line);
	line = std::string();
	while (line.empty() && !std::cin.eof())
	{
		std::cout << "Entrez le surnom : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact[_last_contact_id].set_nickname(line);
	line = std::string();
	while (line.empty() && !std::cin.eof())
	{
		std::cout << "Entrez le numero de telephone : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	contact[_last_contact_id].set_phone_number(line);
	line = std::string();
	while (line.empty() && !std::cin.eof())
	{
		std::cout << "Entrez votre plus grand secret : ";
		std::cin >> line;
		std::cout << std::endl;
	}
	if (line.empty())
		return ;
	contact[_last_contact_id].set_darkest_secret(line);
	contact[_last_contact_id].set_empty(false);
	if(++this->_last_contact_id > 7)
		this->_last_contact_id = 0;
}

void	PhoneBook::_print_field(const std::string &field)
{
	int	space_amount = 10 - field.length();
	int	i;

	if (space_amount < 0)
		space_amount = 0;
	for (i = 0; i < space_amount; i++)
		std::cout << " ";
	for (i = 0; i < 10 - space_amount - 1; i++)
	{
		std::cout << field[i];
	}
	if (field.length() > 10)
		std::cout << ".";
	else
		std::cout << field[i];
}

void	PhoneBook::_print_contact(int id)
{
	if (!this->_contacts[id].is_empty())
	{
		std::cout << "--- Contact n°" << id << " ---" << std::endl;
		std::cout << "Prenom : " << this->_contacts[id].first_name() << std::endl;
		std::cout << "Nom : " << this->_contacts[id].last_name() << std::endl;
		std::cout << "Nickname : " << this->_contacts[id].nickname() << std::endl;
		std::cout << "Phone number : " << this->_contacts[id].phone_number() << std::endl;
		std::cout << "Darkest secret : " << this->_contacts[id].darkest_secret() << std::endl << std::endl;;
	}
}

void	PhoneBook::_print_contacts(void)
{
	std::cout << std::endl;
	for (int i = 0; i < 45; i++)
		std::cout << (i % 11 == 0 ? "|" : "-");
	std::cout << std::endl;
	std::cout << "|";
	this->_print_field("ID");
	std::cout << "|";
	this->_print_field("PRENOM");
	std::cout << "|";
	this->_print_field("NOM");
	std::cout << "|";
	this->_print_field("SURNOM");
	std::cout << "|";
	std::cout << std::endl;
	for (int i = 0; i < 45; i++)
		std::cout << (i % 11 == 0 ? "|" : "-");
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		Contact contact = this->_contacts[i];
		if (!contact.is_empty())
		{
			std::cout << "|";
			this->_print_field(std::to_string(i));
			std::cout << "|";
			this->_print_field(contact.first_name());
			std::cout << "|";
			this->_print_field(contact.last_name());
			std::cout << "|";
			this->_print_field(contact.nickname());
			std::cout << "|";
			std::cout << std::endl;
			for (int i = 0; i < 45; i++)
				std::cout << (i % 11 == 0 ? "|" : "-");
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void PhoneBook::search_contact(void)
{
	std::string	id_str;
	int			id = -1;

	this->_print_contacts();
	if (this->_contacts[0].is_empty())
		return ;
	do
	{
		std::cout << "Entrez l'identifiant du contact a afficher : ";
		std::cin >> id_str;
		std::cout << std::endl;
		if (id_str.empty() || std::cin.eof())
			return ;
		try
		{
			id = std::stoi(id_str);
			if (id < -1 || id > 7 || this->_contacts[id].is_empty())
			{
				std::cout << "Il n'existe pas de contact avec cet identifiant !" << std::endl;
				id = -1;
				continue ;
			}
			this->_print_contact(id);
		}
		catch (const std::invalid_argument &e)
		{
			std::cerr << "Identifiant donné incorrect !" << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Identifiant donné incorrect !" << std::endl;
		}
	}while((id == -1 || id_str.empty()) && !std::cin.eof());
}
