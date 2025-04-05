/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:37 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/04 17:55:49 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Form::Form(const std::string &name_, int gradeToSign_, int gradeToExecute_): Name(name_), signedStatus(false), 
gradeToSign(gradeToSign_), gradeToExecute(gradeToExecute_){
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

void Form::beSigned(Bureaucrat const & other){		
	if (other.getGrade() > this->gradeToSign)
		throw GradeToolLowException();
	else
		this->signedStatus = true;
}

const char *Form::GradeToolHighException::what() const throw(){
	return ("Grade is too high, the grade must be between 1 and 150.");
}

const char *Form::GradeToolLowException::what() const throw(){
	return ("Grade is too low, the grade must be between 1 and 150.");
}
Form::~Form(){}

std::ostream &operator<<(std::ostream & os, const Form & other){
	os << other.getName()<<", Form signed status "<<other.getSignedStatus()<<" grade_to_sign ";
	os <<other.getGradeToSign()<<" grade_to_exec "<<other.getGradeToExecute()<<std::endl;
	return (os);
}