/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/07 15:08:11 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
    DiamondTrap diamond1;
    DiamondTrap diamond2("Hero2");

    diamond2.takeDamage(4);

    DiamondTrap diamond3( diamond2 );

    diamond3.attack("Hero1");

    diamond3.guardGate();
    diamond3.highFivesGuys();
    return (0);
}