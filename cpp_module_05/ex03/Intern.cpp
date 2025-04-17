/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:07:41 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/10 16:03:32 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);
}

Intern::~Intern(){}

const char *Intern::FormExistException::what() const throw(){
	return ("The Form does'nt exist");
}

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
	if (formName.length() == 0 || target.length() == 0)
		throw FormExistException();
	Form *mem = new Form(formName, target);
	std::cout<<"Intern creates " <<formName<<std::endl;
	return (mem);
}
