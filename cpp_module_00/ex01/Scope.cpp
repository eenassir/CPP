/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scope.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:34:00 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/04 13:44:38 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

void Contact::get_fname(std::string name){first_name = name;}
void Contact::get_lname(std::string name){last_name = name;}
void Contact::get_nname(std::string name){nick_name = name;}
void Contact::get_nph(std::string num){number_phone = num;}
void Contact::get_d_sec(std::string da_sec){darkest_secret = da_sec;}

std::string Contact::set_fname(void){return (first_name);}
std::string Contact::set_lname(void){return (last_name);}
std::string Contact::set_nname(void){return (nick_name);}
std::string Contact::set_nph(void){return (number_phone);}
std::string Contact::set_d_sec(void){return (darkest_secret);}


void PhoneBook::get_fname1(std::string str1, int count){con[count].get_fname(str1);}
void PhoneBook::get_lname1(std::string str1, int count){con[count].get_lname(str1);}
void PhoneBook::get_nname1(std::string str1, int count){con[count].get_nname(str1);}
void PhoneBook::get_nph1(std::string str1, int count){con[count].get_nph(str1);}
void PhoneBook::get_d_sec1(std::string str1, int count){con[count].get_d_sec(str1);}

std::string PhoneBook::set_fname1(int i){return (con[i].set_fname());}
std::string PhoneBook::set_lname1(int i){return (con[i].set_lname());}
std::string PhoneBook::set_nname1(int i){return (con[i].set_nname());}
std::string PhoneBook::set_nph1(int i){return (con[i].set_nph());}
std::string PhoneBook::set_d_sec1(int i){return (con[i].set_d_sec());}