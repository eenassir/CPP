/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:27:29 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/25 23:52:58 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	public:
		Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		Span(unsigned int N);
		
		void addNumber(int nbr);
		unsigned int longestSpan();
		unsigned int shortestSpan();
	private:
		unsigned int max_size;
		std::vector<int> array;
};

#endif