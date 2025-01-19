/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:45:35 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/19 23:00:09 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string number_phone;
		std::string darkest_secret;
	public:
		void fname(std::string name){first_name = name;}
		void lname(std::string name){last_name = name;}
		void nname(std::string name){nick_name = name;}
		void nph(std::string num){number_phone = num;}
		void d_sec(std::string da_sec){darkest_secret = da_sec;}
		std::string set_fname(void){return (first_name);}
		std::string set_lname(void){return (last_name);}
		std::string set_nname(void){return (nick_name);}
		std::string set_nph(void){return (number_phone);}
		std::string set_d_sec(void){return (darkest_secret);}
};

class PhoneBook
{
	private:
		Contact con[8];
		int index;
		int count;
		
		int ft_strlen(std::string str){int i = 0;while(str[i])i++;return ( i);}
		
		void ft_print_str(std::string str)
		{
			
			if (ft_strlen(str) > 10)
				std::cout <<std::setw(10)<<(str.substr(0, 9) + ".");
			else
				std::cout <<std::setw(10)<<str;
		}
		
		int ft_atoi(std::string str)
		{
			int result = 0;
			int signe = 1;
			int i = 0;
			
			while (str[i] >= 9 && str[i] <= 32)
				i++;
			if (str[i] == '-' || str[i] == '+')
			{
				if (str[i] == '-')
					signe *= 1;
				i++;
			}
			while ((str[i] >= '0' && str[i] <= '9'))
				result = result * 10 + (str[i++] - '0');
			return (result * signe);
		}
	
	public:
		PhoneBook(void){index = 0;count = 0;}
		void ft_index()
		{
			if (count < 7)
			{
				index++;
				count++;
			}
			else if (count >= 7)
			{
				index = 7;
				count = 0;
			}
		}
		int gg(void){return (index + 1);}
		
		void get_fname(std::string str1){con[count].fname(str1);}
		void get_lname(std::string str1){con[count].lname(str1);}
		void get_nname(std::string str1){con[count].nname(str1);}
		void get_nph(std::string str1){con[count].nph(str1);}
		void get_d_sec(std::string str1){con[count].d_sec(str1);}
		
		std::string set_fname(int i){return (con[i].set_fname());}
		std::string set_lname(int i){return (con[i].set_lname());}
		std::string set_nname(int i){return (con[i].set_nname());}
		std::string set_nph(int i){return (con[i].set_nph());}
		std::string set_d_sec(int i){return (con[i].set_d_sec());}
		
		void ft_display(void)
		{
			std::string str;
			
			std::cout << "      *----------*----------*----------*----------*\n";
			std::cout << "      |          *<<    PHONE BOOK   >>*          |\n";
			std::cout << "      *----------*----------*----------*----------*\n";
			std::cout << "      |     Index|First_name| Last_name| Nick_name|\n";
			std::cout << "      *----------*----------*----------*----------*\n";
			int i = 0;
			while (i < index && i < 8)
			{
				std::cout << "      |"<<std::setw(10) <<i + 1<<"|";
				ft_print_str(set_fname(i)), std::cout<<"|";
				ft_print_str(set_lname(i)), std::cout <<"|";
				ft_print_str(set_nname(i)), std::cout <<"|\n";
				std::cout << "      *----------*----------*----------*----------*\n";
				i++;
			}
			if (index == 0)
			{
				std::cout <<"                   !EMPTY PHONE BOOK!\n";
				return ;
			}
			std::cout <<std::endl<<"*ENTER AN INDEX FROM (1 TO 8):\n> "; 
			std::getline(std::cin, str);
			std::cout <<"\n";
			if (str[0] == '\0')
				return ;
			int j = 0;
			int result = 0;
			
			while (str[j])
			{
				if(!(str[j] >= '0' && str[j] <= '9') && !(str[j] >= 9 &&  str[j] <= 32) && (str[0] != '+'))
				{
					std::cout <<"Invalid index: > \"" << str<< "\"\n";
					return ;
				}
				else if (str[1] == '+')	
				{
					std::cout <<"Invalid index: > \"" << str<< "\"\n";
					return ;
				}
				j++;
			}
			result = ft_atoi(str);
			if (result <= index && result > 0 && result <= 8)
			{
				std::cout <<"->First_name   : "<<set_fname(result - 1) << "\n\n";
				std::cout <<"->Last_name    : "<<set_lname(result - 1) << "\n\n";
				std::cout <<"->Nick_name    : "<<set_nname(result - 1) << "\n\n";
				std::cout <<"->Phone_number : "<<set_nph(result - 1) << "\n\n";
				std::cout <<"->Dark_secret  : "<<set_d_sec(result - 1) << "\n";
				std::cout <<std::endl;
			}
			else
				std::cout <<"There is no contact memeber for the index: " << str << "\n";
		}
};

#endif