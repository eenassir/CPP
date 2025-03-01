/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:16:28 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/14 00:16:29 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "ClapTrap.h"

class ClapTrap
{
    private:
        std::string Name;
        unsigned int HitPoints;
        unsigned int EnergiePoints;
        unsigned int AttackDamage;
    public:
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap &mem);
        ClapTrap &operator=(const ClapTrap &mem);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


};

#endif