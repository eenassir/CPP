/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:29:02 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/09 08:53:30 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nameB)
{
	name = nameB, mem = NULL;
}

void HumanB::attack()
{
	if (mem == NULL)
		std::cout <<name<<" has no weapon.\n";
	else
		std::cout <<name<<" attacks with their "<<mem->getType()<<"\n";
}

void HumanB::setWeapon(Weapon& WeaponB)
{
	mem = &WeaponB;
}