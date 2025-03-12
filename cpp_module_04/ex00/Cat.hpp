/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:01:35 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/11 02:17:37 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CAT_HPP
# define CAT_HPP

#include "Animal.h"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &mem);
		Cat &operator=(const Cat &mem);
		~Cat();
		
		void makeSound() const;
};

#endif

