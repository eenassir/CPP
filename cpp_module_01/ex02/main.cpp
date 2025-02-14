/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:17:24 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/09 08:24:36 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>


int main()
{	
	std::string str = "HI THIS IS BRAIN", *stringPTR = &str, &stringREF = str;
	std::cout <<"\n";
	std::cout <<"*> The memory address of the string variable : "<<&str<<"\n";
	std::cout <<"*> The memory address held by stringPTR      : "<<stringPTR<<"\n";
	std::cout <<"*> The memory address held by stringREF      : "<<&stringREF<<"\n";
	std::cout <<"\n\n";
	std::cout <<"*> The value of the string variable    : "<<str<<"\n";
	std::cout <<"*> The value pointed to by stringPTR   : "<<*stringPTR<<"\n";
	std::cout <<"*> The value pointed to by stringREF   : "<<stringREF<<"\n";
	std::cout <<"\n";
}