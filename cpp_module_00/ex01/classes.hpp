/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:45:35 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/07 00:32:24 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

#include "Header.h"

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string number_phone;
		std::string darkest_secret;
	public:
		void get_fname(std::string name);
		void get_lname(std::string name);
		void get_nname(std::string name);
		void get_nph(std::string num);
		void get_d_sec(std::string da_sec);
		std::string set_fname(void);
		std::string set_lname(void);
		std::string set_nname(void);
		std::string set_nph(void);
		std::string set_d_sec(void);
};

class PhoneBook
{
	private:
		Contact con[8];
	public:
		void get_fname1(std::string str1, int count);
		void get_lname1(std::string str1, int count);
		void get_nname1(std::string str1, int count);
		void get_nph1(std::string str1, int count);
		void get_d_sec1(std::string str1, int count);
		std::string set_fname1(int i);
		std::string set_lname1(int i);
		std::string set_nname1(int i);
		std::string set_nph1(int i);
		std::string set_d_sec1(int i);
		
};

#endif