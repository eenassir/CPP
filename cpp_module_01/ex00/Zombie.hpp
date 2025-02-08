/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:34:54 by eenassir          #+#    #+#             */
/*   Updated: 2025/02/09 00:02:54 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "Zombie.h"

class Zombie
{
	private:
		std::string name;
	public:
		~Zombie(void);
		Zombie(void);
		void announce(void);
		void set_name(std::string name);
};

#endif