/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:29:42 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/17 17:42:15 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.h"

class MateriaSource : public IMateriaSource
{
	private:
        AMateria    *templates[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &mem);
		MateriaSource &operator=(const MateriaSource &mem);
		~MateriaSource();
		
		void learnMateria(AMateria *materia);
		AMateria* createMateria(std::string const &type);
};

#endif
