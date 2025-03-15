/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:26:02 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/13 01:06:19 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.h"

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &mem);
		Brain &operator=(const Brain &mem);
		~Brain();

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
}; 

#endif