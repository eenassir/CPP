/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:06:16 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 23:55:37 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target(""){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	this->target = other.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string const &_target) : AForm("PresidentialPardonForm", 25, 5), target(_target){}

std::string PresidentialPardonForm::getTarget() const {
	return (this->target);	
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (!this->getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() <= this->getGradeToExecute())
		throw GradeToolLowException();
	std::cout <<this->target<<" has been pardoned by Zaphond Beeblebrox"<<std::endl;
}

AForm *PresidentialPardonForm::create(const std::string &target){
	return (new PresidentialPardonForm(target));
}