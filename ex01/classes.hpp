/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:45:35 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/07 20:46:27 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
#define CLASS_H

#include <iostream>

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
		void fname(std::string& name){first_name = name;}
		void lname(std::string& name){last_name = name;}
		void nname(std::string& name){nick_name = name;}
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
		Contact con[3];
		int index;
	
	public:
		PhoneBook(void){index = -1;}
		void ft_index()
		{
			if (index < 2)
				index++;
			else
				index = 0;
		}
		int gg(void){return (index + 1);}
		void get_fname(std::string str1)
		{
			con[index].fname(str1);
		}
		void get_lname(std::string str1){con[index].lname(str1);}
		void get_nname(std::string str1){con[index].nname(str1);}
		void get_nph(std::string str1){con[index].nph(str1);}
		void get_d_sec(std::string str1){con[index].d_sec(str1);}
		void ft_display(void)
		{
			int i = 0;
			std::cout << " ------------------------------------------------ \n";
			std::cout << "| index   | "<< i + 1;
			std::cout << "|\n ------------------------------------------------ \n";
			std::cout << "|fist_name| "<<con[i].set_fname()<<"|\n";
			std::cout << " ------------------------------------------------ \n";
			std::cout << "|last_name| "<<con[i].set_lname()<<"|\n";
			std::cout << " ------------------------------------------------ \n";
			std::cout << "|nick_name| "<<con[i].set_nname()<<"|\n";
			std::cout << " ------------------------------------------------ \n";
		}
};

#endif