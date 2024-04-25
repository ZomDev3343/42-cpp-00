/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:53:36 by tohma             #+#    #+#             */
/*   Updated: 2024/04/25 16:54:43 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	prompt;
	PhoneBook	repertoire;

	do {
		std::cout << "--- ENTREZ UNE COMMANDE (ADD, SEARCH, EXIT) ---" << std::endl;
		std::cin >> prompt;
		if (prompt == "ADD")
			repertoire.add_contact();
		else if (prompt != "SEARCH")
			repertoire.search_contact();
	}while (prompt != "EXIT");
	return (0);
}
