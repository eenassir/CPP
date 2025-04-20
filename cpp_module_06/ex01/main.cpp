/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:13:15 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/20 10:03:01 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data ptr(1, 1.1, 'l', "make");
	Data *ptr1;
	uintptr_t nbr;

	std::cout <<"Before serialisation integer : "<<ptr.int_val<<std::endl;
	std::cout <<"Before serialisation float: "<<ptr.float_val<<std::endl;
	std::cout <<"Before serialisation char: "<<ptr.char_val<<std::endl;
	std::cout <<"Before serialisation string: "<<ptr.string_val<<std::endl;
	std::cout <<std::endl;
	
	nbr = Serializer::serialize(&ptr);
	ptr1 = Serializer::deserializer(nbr);
	
	std::cout <<"After serialisation integer : "<<ptr1->int_val<<std::endl;
	std::cout <<"After serialisation float: "<<ptr1->float_val<<std::endl;
	std::cout <<"After serialisation char: "<<ptr1->char_val<<std::endl;
	std::cout <<"After serialisation string: "<<ptr1->string_val<<std::endl;
}