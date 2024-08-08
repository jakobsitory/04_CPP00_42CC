/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPhoneBook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:16 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:55:27 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Main function for the MyPhoneBook application.
 *
 * This function serves as the entry point for a simple phone book application. It initializes a PhoneBook instance
 * and enters a loop to process user commands. The user can add new contacts, search for existing contacts, or exit
 * the application. The loop continues until the user decides to exit.
 *
 * @return int Returns 0 upon successful completion.
 */
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