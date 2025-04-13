/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:37 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/10 18:32:40 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : Name("Default_Form"), SignedStatus(false), GradeToSign(150), GradeToExecute(150)
{}

AForm::AForm(const std::string &name_, int gradeToSign_, int gradeToExecute_): Name(name_), SignedStatus(false), 
GradeToSign(gradeToSign_), GradeToExecute(gradeToExecute_){
	if (GradeToExecute < 1 || GradeToSign < 1)
		throw GradeToolHighException();
	if (GradeToExecute > 150 || GradeToSign > 150)
		throw GradeToolLowException();
}

AForm::~AForm()
{}

const std::string &AForm::getName() const{
	return (this->Name);
}

bool AForm::getSignedStatus() const{
	return (this->SignedStatus);
}

int AForm::getGradeToSign() const{
	return (this->GradeToSign);	
}

int AForm::getGradeToExecute() const{
	return (this->GradeToExecute);
}

void AForm::beSigned(Bureaucrat const & other){		
	if (other.getGrade() > this->GradeToSign)
		throw GradeToolLowException();
	else
		this->SignedStatus = true;
}

const char *AForm::GradeToolHighException::what() const throw(){
	return ("Grade is too high, the grade must be between 1 and 150.");
}

const char *AForm::GradeToolLowException::what() const throw(){
	return ("Grade is too low, the grade must be between 1 and 150.");
}

const char *AForm::FormNotSignedException::what() const throw(){
	return ("Form is not signed.");
}

std::ostream &operator<<(std::ostream & os, const AForm & other){
	os << other.getName()<<", AForm signed status "<<other.getSignedStatus()<<" grade_to_sign ";
	os <<other.getGradeToSign()<<" grade_to_exec "<<other.getGradeToExecute()<<std::endl;
	return (os);
}