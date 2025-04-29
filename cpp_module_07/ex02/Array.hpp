/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:02:39 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/27 12:29:53 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
class Array
{
	private:
		T *element;
		unsigned int _size;
	public:
		Array() : element(NULL), _size(0){}
		
		Array(const Array &other) : element(NULL), _size(0)
		{
			*this = other;
		}
		
		Array &operator=(const Array &other)
		{
			if (this == &other)
				return (*this);
			if (element)
				delete[] element;
			this->_size = other._size;
			if (_size > 0)
			{	
				this->element = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
				{
					element[i] = other.element[i];
				}
			}
			else
				element = NULL;
			return (*this);
		}
		
		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return (element[index]);
		}

		const T &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::exception();
			return (element[index]);
		}

		~Array()
		{
			if (element)
				delete[] this->element;
		}

		Array(unsigned int n) : _size(n)
		{
			this->element = new T[n];
		}
		
		unsigned int size() const
		{
			return (this->size);
		}
};

#endif