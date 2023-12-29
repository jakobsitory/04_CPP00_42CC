/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:21:48 by jschott           #+#    #+#             */
/*   Updated: 2023/12/13 16:56:30 by jschott          ###   ########.fr       */
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