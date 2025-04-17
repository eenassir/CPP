/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:06:16 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 09:34:32 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &_target) : AForm("PresidentialPardonForm", 25, 5), target(_target){
}

std::string PresidentialPardonForm::getTarget() const {
	return (this->target);	
}

// void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
// 	if (!this->getSignedStatus())
// 		throw FormNotSignedException();
// 	if (executor.getGrade() > this->getGradeToExecute())
// 		throw GradeToolLowException();
// 	std::cout <<this->target<<" has been pardoned by Zaphond Beeblebrox"<<std::endl;
// }
