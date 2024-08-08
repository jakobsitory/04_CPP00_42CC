/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:21:45 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:54:06 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <vector>
#include <string>

/**
 * Constructor that initializes a contact with details provided in an array.
 * 
 * @param input An array of strings containing the contact's details in the following order:
 *              FirstName, LastName, NickName, PhoneNum, DarkSecret.
 */
Contact::Contact	(std::string const input[5])
					: 
					FirstName(input[0]), 
					LastName(input[1]), 
					NickName(input[2]), 
					PhoneNum(input[3]), 
					DarkSecret(input[4])
{
	return;
}

/**
 * Copies the details from another Contact object into this one.
 * 
 * @param src The source Contact object from which to copy the details.
 * @return Returns 0 on success.
 */
int Contact::copy (Contact src)
{
	this->FirstName = src.FirstName;
	this->LastName = src.LastName; 
	this->NickName = src.NickName;
	this->PhoneNum = src.PhoneNum; 
	this->DarkSecret = src.DarkSecret;

	return 0;
}

/**
 * Populates the contact's details from an array of strings.
 * 
 * @param input An array of strings containing the contact's details in the following order:
 *              FirstName, LastName, NickName, PhoneNum, DarkSecret.
 * @return Returns 0 on success.
 */
int Contact::populate (std::string const input[5])
{
	this->FirstName = input[0];
	this->LastName = input[1]; 
	this->NickName = input[2];
	this->PhoneNum = input[3]; 
	this->DarkSecret = input[4];

	return 0;
}

/**
 * Prints a concise summary of the contact's details in a single line.
 * 
 * This method handles formatting for long names by truncating them and appending a period.
 * 
 * @return Returns 0 on success.
 */
int Contact::print_in_line (void) const
{
	if (this->FirstName.find('\t') <= 10)
		std::cout << std::setw(9) << this->FirstName.substr(0, this->FirstName.find('\t')) << ".|";
	else if (this->FirstName.length() > 10)
		std::cout << std::setw(9) << this->FirstName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->FirstName << "|";
	if (this->LastName.find('\t') <= 10)
		std::cout << std::setw(9) << this->LastName.substr(0, this->LastName.find('\t')) << ".|";
	else if (this->LastName.length() > 10)
		std::cout << std::setw(9) << this->LastName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->LastName << "|";
	if (this->NickName.find('\t') <= 10)
		std::cout << std::setw(9) << this->NickName.substr(0, this->NickName.find('\t')) << ".|";
	else if (this->NickName.length() > 10)
		std::cout << std::setw(9) << this->NickName.substr(0, 9) << std::endl;
	else
		std::cout << std::setw(10) << this->NickName << std::endl;
	return 0;
}

/**
 * Prints all details of the contact in a readable format.
 * 
 * @return Returns 0 on success.
 */
int Contact::print_full (void) const
{
	std::cout << "First Name:\t" << this->FirstName << std::endl;
	std::cout << "Last Name:\t" << this->LastName << std::endl;
	std::cout << "Nickname:\t" << this->NickName << std::endl;
	std::cout << "Phone Number:\t" << this->PhoneNum << std::endl;
	std::cout << "Darkest Secret:\t" << this->DarkSecret << std::endl;
	return 0;
}

/**
 * Checks if the contact is empty (i.e., all details are unset).
 * 
 * @return Returns true if empty, false otherwise.
 */
bool Contact::empty (void) const
{
	if (this->FirstName.empty() &&
		this->LastName.empty() &&
		this->NickName.empty() &&
		this->PhoneNum.empty() &&
		this->DarkSecret.empty())
		return true;
	return false;
}

/**
 * Default constructor.
 */
Contact::Contact(void)
{
	return;
}

/**
 * Destructor.
 */
Contact::~Contact(void)
{
	return;
}
