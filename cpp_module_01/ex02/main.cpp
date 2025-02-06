/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:17:24 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/28 00:06:55 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	std::string str = "HI THIS IS BRAIN", *stringPTR = &str, &stringREF = str;
	
	std::cout <<&str<<"\n"<<stringPTR<<"\n"<<&stringREF<<"\n";
	std::cout <<str<<"\n"<<*stringPTR<<"\n"<<stringREF<<"\n";
}