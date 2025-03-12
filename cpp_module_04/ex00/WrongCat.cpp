/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:25:49 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/11 02:54:11 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

WrongCat::WrongCat()
{
	std::cout <<"The WrongCat_default constructor called"<<std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &mem)
{
	std::cout <<"The WrongCat copy constructor called"<<std::endl;
	*this = mem;
}

WrongCat &WrongCat::operator=(const WrongCat &mem)
{
	if (this == &mem)
		return (*this);
	std::cout <<"The WrongCat copy assignement called"<<std::endl;
	this->type = mem.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout <<"The WrongCat destructor called"<<std::endl;
}

void WrongCat::makeSound() const
{
	std::cout <<"wrong meow wrong meow"<<std::endl;	
}