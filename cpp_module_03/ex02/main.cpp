/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/07 15:05:08 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
    FragTrap frag1;
    FragTrap frag2("Hero2");

    frag2.takeDamage(5);

    FragTrap frag3( frag2);

    frag3.beRepaired(5);

    frag3.attack("Hero1");
    return 0;
}