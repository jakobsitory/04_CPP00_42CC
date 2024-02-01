/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:21:45 by jschott           #+#    #+#             */
/*   Updated: 2023/12/13 12:46:37 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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