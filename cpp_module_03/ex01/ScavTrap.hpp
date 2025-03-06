/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:10 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 02:19:38 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &mem);
		ScavTrap &operator=(const ScavTrap &mem);
		~ScavTrap();

		ScavTrap(const std::string &name);
		
		void attack(const std::string &target);
		void guardGate();
};

#endif