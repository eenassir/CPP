/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:35:58 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/17 17:41:02 by eenassir         ###   ########.fr       */
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


		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif