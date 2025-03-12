/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:25:52 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/11 21:43:27 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "Animal.h"

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &mem);
		WrongAnimal &operator=(const WrongAnimal &mem);
		virtual ~WrongAnimal();

		std::string getType(void) const;
		void makeSound() const;
		
};

#endif