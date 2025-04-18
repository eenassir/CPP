/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:07:41 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/18 09:25:40 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(){}

const char *Intern::FormExistException::what() const throw(){
	return ("The Form does'nt exist");
}

Intern::FormType Intern::formType[3] = 
{
	{"shrubbery creation", &ShrubberyCreationForm::create},
	{"robotomy request", &RobotomyRequestForm::create},
	{"presidential pardon", &PresidentialPardonForm::create}
};

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == formType[i].name)
		{
			AForm *form = formType[i].create(target);
			std::cout <<"Intern creates "<<form->getName()<<std::endl;
			return (form);
		}
	}
	std::cout <<"Intern cannot create form: "<<formName<<" (unknown form type)"<<std::endl;
	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form type not found");
}
