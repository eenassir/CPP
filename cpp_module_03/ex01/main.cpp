/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 01:26:57 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
    ScavTrap scav1("Hero1");
    ScavTrap scav2("Hero2");

    scav1.attack("Hero1");
    scav1.takeDamage(30);
    scav1.beRepaired(20);
    scav1.guardGate();

    scav2.attack("Hero2");
    scav2.takeDamage(1);
    scav2.beRepaired(10);
    scav2.guardGate();

    return 0;
}