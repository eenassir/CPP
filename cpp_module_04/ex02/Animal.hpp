/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:48:26 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/12 02:36:42 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Animal.h"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &mem);
		Animal &operator=(const Animal &mem);
		virtual ~Animal();

		
		virtual void makeSound() const = 0;
		std::string getType(void) const;
};

#endif