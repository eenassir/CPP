/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:11:49 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/14 15:43:50 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &other){
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other){
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data *ptr){
	uintptr_t i;

	i = reinterpret_cast<uintptr_t>(ptr);
	return (i);
}

Data *Serializer::deserializer(uintptr_t raw){
	Data *ptr;

	ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}
