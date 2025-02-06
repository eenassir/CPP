/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:28:51 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/29 12:13:54 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string string)
{
	type = string;
}
std::string const Weapon::getType(void)
{
	return (type);
}
void Weapon::setType(std::string arg){type = arg;}