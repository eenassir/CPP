/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:18:09 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/22 16:10:40 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template<typename T>
Array<T>::Array(): element(NULL), size(0){}

template<typename T>
Array<T>::Array(const Array &other) : element(NULL), size(0)
{
	*this = other;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);
	delete [] this->element;
	this->size = other.element;
	this->element = new T[size];
	int i = 0;
	for (; i < size; i++)
	{
		this->element[i] = other.element[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	
}

template<typename T>
Array<T>::Array(unsigned int n) : size(n)
{
	element = new T[n]();
}

template<typename T>
size_t Array<T>::size()
{
	
}