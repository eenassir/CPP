/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:29:42 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/13 01:37:24 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		void learnMateria(AMateria *materia);
		AMateria* createMateria(std::string const &type);
};

#endif