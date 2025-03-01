/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:15:18 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/14 00:15:19 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main() {

    ClapTrap clap1("HERO1");
    ClapTrap clap2("HERO2");

    clap1.attack("HERO2");
    clap2.takeDamage(5);
    clap2.beRepaired(3);
    clap1.takeDamage(5);
    clap1.attack("HERO2");
    clap2.attack("HERO1");

    return 0;
}
