/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:54:57 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/17 16:02:33 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "AMateria.h"
class ICharacter;
class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const & type);
		
		AMateria();
		AMateria(const AMateria &mem);
		AMateria &operator=(const AMateria &mem);
		virtual ~AMateria();

		std::string const & getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif