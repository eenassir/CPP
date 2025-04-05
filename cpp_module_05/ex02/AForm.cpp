/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:37 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/04 17:54:55 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name_, int gradeToSign_, int gradeToExecute_): Name(name_), signedStatus(false), 
gradeToSign(gradeToSign_), gradeToExecute(gradeToExecute_){
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeToolHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeToolLowException();
}

const std::string &AForm::getName() const{
	return (this->Name);
}

bool AForm::getSignedStatus() const{
	return (this->signedStatus);
}

int AForm::getGradeToSign() const{
	return (this->gradeToSign);	
}

int AForm::getGradeToExecute() const{
	return (this->gradeToExecute);
}

void AForm::beSigned(Bureaucrat const & other){		
	if (other.getGrade() > this->gradeToSign)
		throw GradeToolLowException();
	else
		this->signedStatus = true;
}

const char *AForm::GradeToolHighException::what() const throw(){
	return ("Grade is too high, the grade must be between 1 and 150.");
}

const char *AForm::GradeToolLowException::what() const throw(){
	return ("Grade is too low, the grade must be between 1 and 150.");
}

std::ostream &operator<<(std::ostream & os, const AForm & other){
	os << other.getName()<<", AForm signed status "<<other.getSignedStatus()<<" grade_to_sign ";
	os <<other.getGradeToSign()<<" grade_to_exec "<<other.getGradeToExecute()<<std::endl;
	return (os);
}