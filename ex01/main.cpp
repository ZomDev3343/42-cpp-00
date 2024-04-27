/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:53:36 by tohma             #+#    #+#             */
/*   Updated: 2024/04/27 20:51:47 by tohma            ###   ########.fr       */
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
		else if (prompt == "SEARCH")
			repertoire.search_contact();
	}while (prompt != "EXIT" && !std::cin.eof());
	return (0);
}
