/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:37 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/18 00:39:31 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : Name("Default_Form"), SignedStatus(false), GradeToSign(150), GradeToExecute(150){}

AForm::AForm(const AForm &other) : Name(""), SignedStatus(false), GradeToSign(1), GradeToExecute(1)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	this->SignedStatus = getSignedStatus();
	return (*this);
}
AForm::~AForm(){}

AForm::AForm(const std::string &name_, int gradeToSign_, int gradeToExecute_): Name(name_), SignedStatus(false), 
GradeToSign(gradeToSign_), GradeToExecute(gradeToExecute_){
	if (GradeToExecute < 1 || GradeToSign < 1)
		throw GradeToolHighException();
	if (GradeToExecute > 150 || GradeToSign > 150)
		throw GradeToolLowException();
}


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
	if (other.getGrade() <= this->GradeToSign)
		this->SignedStatus = true;
	else
		throw GradeToolLowException();
}

const char *AForm::GradeToolHighException::what() const throw(){
	return ("Grade is too high");
}

const char *AForm::GradeToolLowException::what() const throw(){
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw(){
	return ("Form is not signed.");
}

std::ostream &operator<<(std::ostream & os, const AForm & other){
	os << other.getName()<<", AForm signed status "<<other.getSignedStatus()<<" grade_to_sign ";
	os <<other.getGradeToSign()<<" grade_to_exec "<<other.getGradeToExecute()<<std::endl;
	return (os);
}