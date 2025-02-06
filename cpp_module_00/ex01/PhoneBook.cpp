/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:33:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/04 13:43:49 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

void ft_print_manual(void)
{
	std::cout <<"*-------------------------------------------------*\n";
	std::cout <<"|         PHONE BOOK COMMANDS MANUAL              |\n";
	std::cout <<"*--------*----------------------------------------*\n";
	std::cout <<"| ADD    | -for adding a conatct                  |\n";
	std::cout <<"*--------*----------------------------------------*\n";
	std::cout <<"| SEARCH | -for searching and showing the contacts|\n";
	std::cout <<"*--------*----------------------------------------*\n";
	std::cout <<"| EXIT   | -for exiting the programme             |\n";
	std::cout <<"*--------*----------------------------------------*\n";
	std::cout << "  ENTER A COMMAND: <ADD>/<SEARCH>/<EXIT>\n> ";
}

void ft_print_str(std::string str)
{
	
	if (str.length() > 10)
		std::cout <<std::setw(10)<<(str.substr(0, 9) + ".");
	else
		std::cout <<std::setw(10)<<str;
}

void ft_display(PhoneBook phone, int index)
{
	std::string str;
	int i = 0, j = 0, result = 0;
	std::stringstream stream;
	
	std::cout << "      *----------*----------*----------*----------*\n";
	std::cout << "      |          *<<    PHONE BOOK   >>*          |\n";
	std::cout << "      *----------*----------*----------*----------*\n";
	std::cout << "      |     Index|First_name| Last_name| Nick_name|\n";
	std::cout << "      *----------*----------*----------*----------*\n";
	while (i < index && i < 8)
	{
		std::cout << "      |"<<std::setw(10) <<i + 1<<"|";
		ft_print_str(phone.set_fname1(i)), std::cout<<"|";
		ft_print_str(phone.set_lname1(i)), std::cout <<"|";
		ft_print_str(phone.set_nname1(i)), std::cout <<"|\n";
		std::cout << "      *----------*----------*----------*----------*\n";
		i++;
	}
	if (index == 0)
		return(void(std::cout <<"                   !EMPTY PHONE BOOK!\n"));
	(std::cout <<std::endl<<"*ENTER AN INDEX FROM (1 TO 8):\n> ", std::getline(std::cin, str), std::cout <<"\n");
	if (str[0] == '\0')
		return (void(std::cout <<"EMPTY FIELD!!!!\n"));
	while (str[j])
	{
		if(!(str[j] >= '0' && str[j] <= '9') && !(str[j] >= 9 &&  str[j] <= 32) && (str[0] != '+'))
			return (void(std::cout <<"*Invalid index format: > \"" << str<< "\"!\n"));
		else if (str[1] == '+')	
			return(void(std::cout <<"*Invalid index format: > \"" << str<< "\"!\n"));
		j++;
	}
	stream.clear();
	stream << str;
	stream >> result;
	// if (!(stream >> result) || !stream.eof())
	// 	result = -1;
	if (result - 1 < index && (result >= 1 && result <= 8))
	{
		std::cout <<"->First_name   : "<<phone.set_fname1(result - 1) << "\n\n";
		std::cout <<"->Last_name    : "<<phone.set_lname1(result - 1) << "\n\n";
		std::cout <<"->Nick_name    : "<<phone.set_nname1(result - 1) << "\n\n";
		std::cout <<"->Phone_number : "<<phone.set_nph1(result - 1) << "\n\n";
		std::cout <<"->Dark_secret  : "<<phone.set_d_sec1(result - 1) << "\n";
		std::cout <<std::endl;
		return ;
	}
	std::cout <<"*There is no contact memeber for the index: " << str << "\n";
}

int is_printable(std::string str)
{
	int flag = 0;
	
	for(unsigned long k = 0; k < str.length(); k++)
		(!isprint(str[k])) && (flag = 1);
	return (flag);
}

int main()
{
    PhoneBook phone;
    std::string str, temp_fname, temp_lname, temp_nname, temp_phone, temp_secret;
    int index = 0, count = 0, flag = 0;
    
    ft_print_manual();
    while ((std::getline(std::cin, str)))
    {
		if (is_printable(str) == 1 || std::cin.eof())
		{
			(std::cout <<"\n"<<"INVALID INPUT COMMAND!!\n", std::cout << "ENTER A COMMAND: <ADD>/<SEARCH>/<EXIT> \n> ");
			continue;
		}
        if (str == "ADD" and str.length() == 3)
        {
        	flag = 0;
            std::cout <<"------------------------------------------------------------------------------";
            (std::cout << "\nEntre the first_name:\n> ", std::getline(std::cin, temp_fname), (temp_fname.length() == 0 || is_printable(temp_fname)) && (flag = 1));
            (std::cout << "\nEntre the last_name:\n> ", std::getline(std::cin, temp_lname), (temp_lname.length() == 0 || is_printable(temp_lname)) && (flag = 1));
            (std::cout << "\nEntre the nick_name:\n> ", std::getline(std::cin, temp_nname), (temp_nname.length() == 0 || is_printable(temp_nname)) && (flag = 1));
            (std::cout << "\nEntre the phone_number:\n> ", std::getline(std::cin, temp_phone), (temp_phone.length() == 0 || is_printable(temp_phone)) && (flag = 1));
            (std::cout << "\nEntre the darkest_secret:\n> ", std::getline(std::cin, temp_secret), (temp_secret.length() == 0 || is_printable(temp_secret)) && (flag = 1));
            if (flag == 0)
            {
                (phone.get_fname1(temp_fname, count), phone.get_lname1(temp_lname, count), phone.get_nname1(temp_nname, count));
				(phone.get_nph1(temp_phone, count), phone.get_d_sec1(temp_secret, count));
                if (count >= 7)
                    count = 0;
                else
                    count++, (index < 8) && (index++);
            }
            std::cout <<"------------------------------------------------------------------------------\n";
        }
		else if (str == "SEARCH")
		{
			std::cout <<"------------------------------------------------------------------------------\n";
			ft_display(phone, index);
			std::cout <<"------------------------------------------------------------------------------\n";
		}
		else if (str == "EXIT")
			break ;	
		else
			std::cout <<"INVALID INPUT COMMAND!!\n";
		std::cout << "ENTER A COMMAND: <ADD>/<SEARCH>/<EXIT> \n> ";
	}
	return (0);
}
