/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:34:54 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/19 23:19:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

#include "Zombie.h"

class Zombie
{
	private:
		std::string name;
		int ft_strcmp(std::string s1, std::string s2, int n)
		{
			int i = 0;

			while (s1[i] == s2[i] && i < n - 1)
				i++;
			return (s1[i] - s2[i]);
		}
		void announce(void)
		{
			if (ft_strcmp(name, "FOO", 4) == 0)
				std::cout <<name<<": BraiiiiiiinnnzzzZ...\n";
			else
				std::cout <<"<"<<name<<">: BraiiiiiiinnnzzzZ...\n";
		}
		
	public:
		void memeber(void)
		{
			std::string str;
			
			getline (std::cin, str);
			name = str;
			announce();
		}
};

#endif