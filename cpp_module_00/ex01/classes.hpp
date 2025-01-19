/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:45:35 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/18 23:19:26 by eenassir         ###   ########.fr       */
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
		int index;
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
			int i = 0;
			
			if (ft_strlen(str) > 10)
				std::cout <<std::setw(10)<<(str.substr(0, 9) + ".");
			else
				std::cout <<std::setw(10)<<str;
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
				index = 8;
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
			std::cout << "      *----------*----------*----------*----------*\n";
			std::cout << "      |   Index  |First_name|Last_name |Nick_name |\n";
			std::cout << "      *----------*----------*----------*----------*\n";
			int i = 0;
			while (i < index)
			{
				std::cout << "      |"<<std::setw(10) <<i + 1<<"|";
				ft_print_str(set_fname(i % 7));
				std::cout<<"|";
				ft_print_str(set_lname(i % 7));
				std::cout <<"|";
				ft_print_str(set_nname(i % 7));
				std::cout <<"|\n";
				std::cout << "      *----------*----------*----------*----------*\n";
				i++;
			}
			std::cout <<std::endl;
		}
};

#endif