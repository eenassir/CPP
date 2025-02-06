/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:29:02 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/29 12:50:19 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nameB){name = nameB, mem = nullptr;}
void HumanB::attack()
{
	if (mem == nullptr)
		std::cout <<"<"<<name<<">"<<" attacks with their\n";
	else
		std::cout <<"<"<<name<<">"<<" attacks with their "<<mem->getType()<<"\n";
}
void HumanB::setWeapon(Weapon& WeaponB){mem = &WeaponB;}