/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:21:45 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:52:22 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

/**
 * Represents a contact in an address book.
 * 
 * This class models a contact with various personal details. It supports creating empty contacts, populating contacts
 * with specific details, copying details from another contact, printing contact information in a concise line or in
 * full detail, and checking if a contact is empty (i.e., lacks any detail).
 */
class Contact
{
private:
	std::string FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNum;
	std::string	DarkSecret;

public:
	Contact (void);
	Contact (std::string const input[5]);
	int populate (std::string const input[5]);
	int copy (Contact src);
	int print_in_line (void) const;
	int print_full (void) const;
	bool empty (void) const;
	~Contact();

};

#endif