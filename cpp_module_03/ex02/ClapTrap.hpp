/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:22:00 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 02:18:08 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "ClapTrap.h"

class ClapTrap
{
    protected:
        std::string Name;
        unsigned int HitPoints;
        unsigned int EnergiePoints;
        unsigned int AttackDamage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &mem);
        ClapTrap &operator=(const ClapTrap &mem);
        ~ClapTrap();
        
        ClapTrap(const std::string &_name);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif