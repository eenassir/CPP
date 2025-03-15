/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:35:58 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 17:39:56 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(const std::string &type);
		
		Cure();
		Cure(const Cure &mem);
		Cure &operator=(const Cure &mem);
		~Cure();


		AMateria *Cure::clone() const;
		void use(ICharacter& target);
};

#endif