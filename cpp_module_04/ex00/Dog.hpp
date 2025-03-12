/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:16 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/11 02:18:18 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.h"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &mem);
		Dog &operator=(const Dog &mem);
		~Dog();
		void makeSound() const;
};

#endif