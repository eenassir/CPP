/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:23:59 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/09 00:08:24 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::~Zombie(void){std::cout <<"* "<<name<<" is destroyed.\n";}
Zombie::Zombie(void){};
void Zombie::announce(void){std::cout <<"*> "<<name<<": BraiiiiiiinnnzzzZ...\n";}
void Zombie::get_name(std::string str){name = str;}