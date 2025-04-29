/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:13:09 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/29 10:13:08 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		MutantStack() : std::stack<T>(){}
		
		MutantStack(const MutantStack &other) : std::stack<T>(other){}
		
		MutantStack &operator=(const MutantStack &other)
		{
			if (this == &other)
				return (*this);
			std::stack<T>::operator=(other);
			return (*this);
		}
		
		~MutantStack(){}

		iterator begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}

		const_iterator begin() const
		{
			return (this->c.begin());
		}

		const_iterator end() const
		{
			return (this->c.end());
		}


};

#endif