/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:33:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/19 22:05:43 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

int ft_strcmp(std::string s1, std::string s2, int n)
{
	int i = 0;
	
	while ((s1[i] && s1[i] == s2[i]) && i < n - 1)
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

void f()
{
	system("leaks PhoneBook");
}

int main()
{
	PhoneBook phone;
	std::string str;
	
	std::cout <<"*-------------------------------------------------*\n";
	std::cout <<"|         PHONE BOOK COMMANDS MANUAL              |\n";
	std::cout <<"*--------*----------------------------------------*\n";
	std::cout <<"| ADD    | -for add a conatct                     |\n";
	std::cout <<"*--------*----------------------------------------*\n";
	std::cout <<"| SEARCH | -for searching and showing the contacts|\n";
	std::cout <<"*--------*----------------------------------------*\n";
	std::cout <<"| EXIT   | -for exiting the programme             |\n";
	std::cout <<"*--------*----------------------------------------*\n";
	std::cout << "  ENTER A COMMAND: <ADD>/<SEARCH>/<EXIT> \n> ";
	while ((std::getline(std::cin, str)))
	{
		if (ft_strcmp(str, "ADD", 4) == 0)
		{
			std::cout <<"------------------------------------------------------------------------------";
			std::cout << "\nEntre the first_name:\n> ";
			std::getline(std::cin, str);
			phone.get_fname(str);
			
			std::cout << "\nEntre the last_name:\n> ";
			std::getline(std::cin, str);
			phone.get_lname(str);
			
			std::cout << "\nEntre the nick_name:\n> ";
			std::getline(std::cin, str);
			phone.get_nname(str);
			
			std::cout << "\nEntre the phone_number:\n> ";
			std::getline(std::cin, str);
			phone.get_nph(str);
			
			std::cout << "\nEntre the darkest_secret:\n> ";
			std::getline(std::cin, str);
			phone.get_d_sec(str);
			std::cout <<"------------------------------------------------------------------------------\n";
			phone.ft_index();
		}
		else if (ft_strcmp(str, "SEARCH", 7) == 0)
		{
			std::cout <<"------------------------------------------------------------------------------\n";
			phone.ft_display();
			std::cout <<"------------------------------------------------------------------------------\n";	
		}
		else if (ft_strcmp(str, "EXIT", 5) == 0)
			break ;	
		else
			std::cout <<"INVALID INPUT COMMAND!!\n";
		std::cout << "ENTER A COMMAND: <ADD>/<SEARCH>/<EXIT> \n> ";
	}
	return (0);
}
