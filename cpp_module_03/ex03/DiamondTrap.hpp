/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:28:57 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 18:24:07 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &mem);
		DiamondTrap &operator=(const DiamondTrap &mem);
		~DiamondTrap();

		DiamondTrap(const std::string &name);

		void attack(const std::string &target);
		void whoAmI(void);
};

#endif