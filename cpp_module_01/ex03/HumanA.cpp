/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:29:10 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/29 12:21:28 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string nameA, Weapon& weaponA) : mem(weaponA){name = nameA;}
void HumanA::attack(){std::cout <<"<"<<name<<"> "<<"attacks with their "<<mem.getType()<<"\n";}
