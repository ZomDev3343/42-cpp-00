/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:24:41 by tohma             #+#    #+#             */
/*   Updated: 2024/04/27 20:30:49 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

void	print_upper(char *str)
{
	while (*str)
	{
		std::cout << (char) toupper(*str);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 0;
		while (++i < ac)
			print_upper(av[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}