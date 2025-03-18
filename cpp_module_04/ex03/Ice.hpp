/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:37:33 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/17 17:41:06 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.h"

class Ice : public AMateria
{
	public:
		Ice(const std::string &type);
		
		Ice();
		Ice(const Ice &mem);
		Ice &operator=(const Ice &mem);
		~Ice();
		

		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif