/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:28:45 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/09 00:17:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "Weapon.h"

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string str);
		std::string const getType(void);
		void setType(std::string arg);
};

#endif