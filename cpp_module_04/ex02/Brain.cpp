/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:00:48 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/12 02:23:02 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

Brain::Brain()
{
	std::cout <<"The Brain default constructor called"<<std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Brain_def";
}

Brain::Brain(const Brain &mem)
{
	std::cout <<"The Brain copy constructor called"<<std::endl;
	*this = mem;
}

Brain &Brain::operator=(const Brain &mem)
{
	if (this == &mem)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = mem.ideas[i];
	std::cout <<"The Brain copy assignement called"<<std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout <<"The Brain destructor called"<<std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return ("Invalid idea index\n");
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

