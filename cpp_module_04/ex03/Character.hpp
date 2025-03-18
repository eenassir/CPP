/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:27:26 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/17 23:34:57 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.h"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *slot[4];
		AMateria *saved_slots[4];
	public:
		Character();
		Character(const Character &mem);
		Character &operator=(const Character &mem);
		~Character();
		Character(const std::string &Name);
		
		std::string const & getName() const;
		std::string const & getType() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif