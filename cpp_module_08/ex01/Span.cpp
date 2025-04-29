/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:27:27 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/29 14:34:06 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <sstream>
#include <algorithm>

Span::Span() : max_size(0){}

Span::Span(const Span &other)
{
	*this = other;	
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	this->max_size = other.max_size;
	this->array = other.array;
	return (*this);
}

Span::~Span(){}

Span::Span(unsigned int N) : max_size(N)
{
	array.reserve(max_size);
}

void Span::addNumber(int nbr)
{
	if (array.size() >= max_size)
		throw std::out_of_range("Span is already full");
	array.push_back(nbr);
}

unsigned int Span::shortestSpan()
{
	if (array.size() <= 1)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> sorted = array;
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	std::vector<int>::iterator it = sorted.begin();
	for (; it != (sorted.end() - 1); ++it)
	{
		unsigned int currentSpan = static_cast<unsigned int>(*(it + 1) - *it);
		if (currentSpan < minSpan)
			minSpan = currentSpan;
	}
	return (minSpan);
}

unsigned int Span::longestSpan()
{
	if (array.size() <= 1)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int>::const_iterator minNbr = std::min_element(array.begin(), array.end());
	std::vector<int>::const_iterator maxNbr = std::max_element(array.begin(), array.end());
	return (static_cast<unsigned int>(*maxNbr - *minNbr));
}

int getRand()
{
	return (rand() % 100);
}

void Span::addMultipleNbr()
{
	std::vector<int> mem(max_size);
	srand(static_cast<unsigned int>(time(NULL)));
	std::generate(mem.begin(), mem.end(), getRand);
	array.swap(mem);
}