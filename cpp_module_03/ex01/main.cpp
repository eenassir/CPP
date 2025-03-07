/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/07 15:02:48 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
    ScavTrap scav1;
    ScavTrap scav2("Hero2");

    scav1.takeDamage(2);
    scav2.takeDamage(3);

    ScavTrap scav3( scav2 );

    scav1.beRepaired(2);
    scav3.beRepaired(3);

    scav3.attack("Hero1");

    return 0;
}