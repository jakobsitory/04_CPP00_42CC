/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPhoneBook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:16 by jschott           #+#    #+#             */
/*   Updated: 2023/12/13 17:07:09 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	std::string command;
	PhoneBook	my_phonebook ;

	std::cout << "Welcome to MyPhoneBook!" << std::endl;
	while (1)
	{
		std::cout << std::endl << "Enter one of the following commands to:" << std::endl;
		std::cout << "ADD\ta new contact" << std::endl;
		std::cout << "SEARCH\tfor existing contacts" << std::endl;
		std::cout << "EXIT\tMyPhoneBook" << std::endl << std::endl;

		if (!std::getline(std::cin, command))
			std::exit(EXIT_FAILURE);

		if (!command.compare("ADD"))
			my_phonebook.add ();
		if (!command.compare("SEARCH"))
			my_phonebook.search ();
		if (!command.compare("EXIT"))
			break ;
	}
	return 0;
}