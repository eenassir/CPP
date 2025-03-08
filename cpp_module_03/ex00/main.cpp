/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:15:18 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/08 00:52:44 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main() {

    ClapTrap clap1;
    ClapTrap clap2("HERO2");
    
    clap2.takeDamage(5);
    
    ClapTrap clap3( clap2 );

    clap3.beRepaired(6);
    clap3.attack("hero");

    return 0;
}
