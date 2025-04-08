/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:07:41 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/08 18:57:43 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char *Intern::FormExistException::what() const throw(){
	return ("The Form does'nt exist");
}

Form *Intern::makeForm(const )
