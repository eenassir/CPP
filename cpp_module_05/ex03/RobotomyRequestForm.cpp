/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:20:36 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/07 16:21:12 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string const &_target) : AForm("RobotomyRequestForm", 72, 45), target(_target){
}

std::string RobotomyRequestForm::getTarget() const{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if (!getSignedStatus())
		throw FormNotSignedException();	
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeToolLowException();
	std::cout <<"* DRILLING NOISES * Bzzzzzz... Drrrrrrr...."<<std::endl;

	std::srand(std::time(NULL));

	if (std::rand() % 2)
		std::cout <<this->target <<"has been robotomized successfuly"<<std::endl;
	else
		std::cout <<"Robotomy of "<<this->target<<" failed!"<<std::endl;
}