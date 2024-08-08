/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:21:48 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:54:58 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include "Contact.hpp"

/**
 * @file PhoneBook.hpp
 * @brief Defines the PhoneBook class for managing a collection of contacts.
 *
 * The PhoneBook class provides functionalities to add, search, and check if the phone book is empty.
 * It encapsulates a fixed-size array of Contact objects, representing individual contacts in the phone book,
 * and a counter to keep track of the current number of contacts.
 */
class PhoneBook
{
private:
	Contact phonebook_index[8];
	int		contact_count;

public:
	PhoneBook();
	~PhoneBook();

	int	add (void);
	int	search (void) const;
	int empty (void) const;
};

#endif