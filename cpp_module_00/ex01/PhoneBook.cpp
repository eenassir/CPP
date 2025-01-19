/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:33:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/18 15:59:58 by eenassir         ###   ########.fr       */
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

int main(int ac, char **av)
{
	PhoneBook phone;
	std::string str;
	
	
	std::cout << "Hello user: the expected commands to add a contact are: ADD, SEARCH, EXIT" << std::endl;
	while ((std::getline(std::cin, str)))
	{
		if (ft_strcmp(str, "ADD", 4) == 0)
		{
			std::cout << phone.gg();
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
			std::cout <<std::endl;
			phone.ft_index();
		}
		else if (ft_strcmp(str, "SEARCH", 7) == 0)
			phone.ft_display();
		else if (ft_strcmp(str, "EXIT", 5) == 0)
			break ;
	}
}
