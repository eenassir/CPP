/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 03:42:18 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main()
{
	DiamondTrap ll("Hero");

	ll.attack("Hero1");
    ll.takeDamage(30);
    ll.beRepaired(20);
	ll.whoAmI();
}