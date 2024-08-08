/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:03:12 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:50:02 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 

/**
 * A simple program that mimics a megaphone, amplifying the input text to uppercase.
 * 
 * @param argc The number of command line arguments.
 * @param argv An array of character pointers representing the command line arguments.
 * @return Returns 0 upon successful completion.
 */
int main(int argc, char *argv[])
{
	std::vector<std::string> input;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	
	for (int i = 1; i < argc; i++)
	{
		std::string word(argv[i]);
		std::transform(word.begin(), word.end(), word.begin(), ::toupper);
		std::cout << word;
		if (i < argc)
			std::cout << " ";
	}
	std::cout << std::endl;
	
	return (0);
}