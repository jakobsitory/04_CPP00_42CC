/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:21:45 by jschott           #+#    #+#             */
/*   Updated: 2023/12/13 16:30:14 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <vector>
#include <string>

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

int Contact::copy (Contact src)
{
	this->FirstName = src.FirstName;
	this->LastName = src.LastName; 
	this->NickName = src.NickName;
	this->PhoneNum = src.PhoneNum; 
	this->DarkSecret = src.DarkSecret;

	return 0;
}


int Contact::populate (std::string const input[5])
{
	this->FirstName = input[0];
	this->LastName = input[1]; 
	this->NickName = input[2];
	this->PhoneNum = input[3]; 
	this->DarkSecret = input[4];

	return 0;
}

int Contact::print_in_line (void) const
{
	if (this->FirstName.length() > 10)
		std::cout << std::setw(9) << this->FirstName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->FirstName << "|";
	if (this->LastName.length() > 10)
		std::cout << std::setw(9) << this->LastName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << this->LastName << "|";
	if (this->NickName.length() > 10)
		std::cout << std::setw(9) << this->NickName.substr(0, 9) << std::endl;
	else
		std::cout << std::setw(10) << this->NickName << std::endl;
	return 0;
}

int Contact::print_full (void) const
{
	std::cout << "First Name:\t" << this->FirstName << std::endl;
	std::cout << "Last Name:\t" << this->LastName << std::endl;
	std::cout << "Nickname:\t" << this->NickName << std::endl;
	std::cout << "Phone Number:\t" << this->PhoneNum << std::endl;
	std::cout << "Darkest Secret:\t" << this->DarkSecret << std::endl;
	return 0;
}

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

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}
