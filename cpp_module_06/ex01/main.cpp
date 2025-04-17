/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:13:15 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/14 15:42:07 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data ptr(1, 1.1, 'l', "make");
	Data *ptr1;
	uintptr_t nbr;

	std::cout <<"Before serialisation integer : "<<ptr.a<<std::endl;
	std::cout <<"Before serialisation float: "<<ptr.b<<std::endl;
	std::cout <<"Before serialisation char: "<<ptr.c<<std::endl;
	std::cout <<"Before serialisation string: "<<ptr.other<<std::endl;
	std::cout <<std::endl;
	
	nbr = Serializer::serialize(&ptr);
	ptr1 = Serializer::deserializer(nbr);
	
	std::cout <<"After serialisation integer : "<<ptr1->a<<std::endl;
	std::cout <<"After serialisation float: "<<ptr1->b<<std::endl;
	std::cout <<"After serialisation char: "<<ptr1->c<<std::endl;
	std::cout <<"After serialisation string: "<<ptr1->other<<std::endl;
}