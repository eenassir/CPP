/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impliment.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:28:42 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/20 10:50:35 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "header.h"
#include <exception>
#include <stdexcept>

Base * generate(void)
{
	std::srand(time(NULL));
	int getRandomValue = rand() % 3;
	switch (getRandomValue)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout <<"A"<<std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout <<"B"<<std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout<<"C"<<std::endl;
		return ;
	}
	else
		std::cout <<"Unknown type"<<std::endl;
}

void identify(Base& p)
{	
	try{
		(void)dynamic_cast<A&>(p);
		std::cout <<"A"<<std::endl;
		return ;
	}
	catch(const std::exception &){}
	 
	try{
		(void)dynamic_cast<B&>(p);
		std::cout <<"B"<<std::endl;
		return ;
	}
	catch(const std::exception &){}
	
	try{
		(void)dynamic_cast<C&>(p);
		std::cout <<"C"<<std::endl;
		return ;
	}
	catch(const std::exception &){}
	
	std::cout <<"Unknown type"<<std::endl;
}


