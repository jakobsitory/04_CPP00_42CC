/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:03:31 by jschott           #+#    #+#             */
/*   Updated: 2023/12/13 17:06:03 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int PhoneBook::empty (void) const
{
	for (int i = 0; i < 8; i++)
	{
		if (!this->phonebook_index[i].empty())
			return 0;
	}
	return 1;
}

int	PhoneBook::add (void)
{

	std::string keys[5] = {
		"First Name:\t", "Last Name:\t", "Nickname:\t",
		"Phone Number:\t", "Darkest Secret:\t"
	};
	std::string values[5];

	for (int i = 0; i < 5; i++)
	{
		std::cout << keys[i];
		if (!std::getline(std::cin, values[i]))
				std::exit(EXIT_FAILURE);
		if (values[i].empty())
			i--;
	}

	const Contact newcontact (values);
	this->phonebook_index[contact_count].copy (newcontact);
	this->contact_count = (this->contact_count + 1) % 8;
	return 0;
}

int	PhoneBook::search (void) const
{
	std::string	input;
	
	if (this->empty())
	{
		std::cout << "MyPhoneBook is empty" << std::endl;
		return 127;
	}
	
	std::cout << "index     |first name|last name |nickname  " << std::endl;
	for (int i = 0; i <= 7; i++)
	{
		if (this->phonebook_index[i].empty())
			break ;
		std::cout <<std::setw(10) << i << "|";
		this->phonebook_index[i].print_in_line();
	}

	while (1)
	{
		std::cout << std::endl << "enter index to view contact details:" << std::endl;
		if (!std::getline(std::cin, input))
			std::exit(EXIT_FAILURE);
		std::istringstream iss(input);

		int input_int;
		if (iss >> input_int)
		{
			if (input_int < 0 \
					|| input_int > contact_count \
					|| this->phonebook_index[input_int].empty())
				std::cout << "invalid input";
			else
			{	
				std::cout << std::endl;
				this->phonebook_index[input_int].print_full();
				break ;
			}
		}
		else
		std::cout << "invalid input";
	}
	std::cout << std::endl << "press enter to return to main menu";
	if (!std::getline(std::cin, input))
			std::exit(EXIT_FAILURE);
	return 0;
}

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
	return;
}

PhoneBook::~PhoneBook()
{
	return;
}
