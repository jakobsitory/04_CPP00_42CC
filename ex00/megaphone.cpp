/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:03:12 by jschott           #+#    #+#             */
/*   Updated: 2023/12/11 11:42:00 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 

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