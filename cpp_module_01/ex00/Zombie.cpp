/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:45:55 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/09 00:06:30 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::~Zombie(void){std::cout<<"\n* "<<name<<" is destroyed.\n\n";}
Zombie::Zombie(void){}
void Zombie::announce(void){std::cout<<"*> "<<name<<" : BraiiiiiiinnnzzzZ...\n";}
void Zombie::set_name(std::string str){name = str;}