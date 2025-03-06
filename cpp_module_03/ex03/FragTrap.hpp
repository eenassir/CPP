/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:24:26 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 18:23:57 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.h"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap (const FragTrap &mem);
		FragTrap &operator=(const FragTrap &mem);
		~FragTrap();
		
		FragTrap(const std::string &name);
		
		void highFivesGuys(void);
};

#endif