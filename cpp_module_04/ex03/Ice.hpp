/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:37:33 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 17:39:49 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(const std::string &type);
		
		Ice();
		Ice(const Ice &mem);
		Ice &operator=(const Ice &mem);
		~Ice();
		

		AMateria *Ice::clone() const;
		void use(ICharacter& target);
};

#endif