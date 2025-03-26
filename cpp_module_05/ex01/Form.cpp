/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:37 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/25 15:21:50 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name_, int gradeToSign_, int gradeToExecute_): Name(name_), signedStatus(false), gradeToSign(gradeToSign_), gradeToExecute(gradeToExecute_)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeToolHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeToolLowException();
}

const std::string &Form::getName() const{
	return (this->Name);
}

bool Form::getSignedStatus() const{
	return (this->signedStatus);
}

int Form::getGradeToSign() const{
	return (this->gradeToSign);	
}

int Form::getGradeToExecute() const{
	return (this->gradeToExecute);
}

void Form::beSigned(const Bureaucrat & other)
{		
	if (other.getGrade() > this->gradeToSign)
		throw GradeToolLowException();
	this->signedStatus = true;
}

const char *Form::GradeToolHighException::what() const throw(){
	return ("The grade must be between 1 and 150");
}

const char *Form::GradeToolLowException::what() const throw(){
	return ("The grade must be between 1 and 150");
}

std::ostream &operator<<(std::ostream & os, const Form & other)
{
	os << other.getName() << std::endl;
	os << other.getSignedStatus()<<std::endl;
	os << other.getGradeToSign()<<std::endl;
	os << other.getGradeToExecute()<<std::endl;
	return (os);
}