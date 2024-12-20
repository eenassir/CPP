/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:45:35 by eenassir          #+#    #+#             */
/*   Updated: 2024/12/14 10:46:27 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <stdio.h>

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
		void get_fname(std::string& name){first_name = name;}
		void get_lname(std::string& name){last_name = name;}
		void get_nname(std::string& name){nick_name = name;}
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
	Contact contacts[8];
};

#endif