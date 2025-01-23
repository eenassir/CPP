/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:45:35 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/22 08:46:35 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string number_phone;
		std::string darkest_secret;
	public:
		void get_fname(std::string name){first_name = name;}
		void get_lname(std::string name){last_name = name;}
		void get_nname(std::string name){nick_name = name;}
		void get_nph(std::string num){number_phone = num;}
		void get_d_sec(std::string da_sec){darkest_secret = da_sec;}
		
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
	public:
		void get_fname1(std::string str1, int count){con[count].get_fname(str1);}
		void get_lname1(std::string str1, int count){con[count].get_lname(str1);}
		void get_nname1(std::string str1, int count){con[count].get_nname(str1);}
		void get_nph1(std::string str1, int count){con[count].get_nph(str1);}
		void get_d_sec1(std::string str1, int count){con[count].get_d_sec(str1);}
		
		std::string set_fname1(int i){return (con[i].set_fname());}
		std::string set_lname1(int i){return (con[i].set_lname());}
		std::string set_nname1(int i){return (con[i].set_nname());}
		std::string set_nph1(int i){return (con[i].set_nph());}
		std::string set_d_sec1(int i){return (con[i].set_d_sec());}
		
};

#endif