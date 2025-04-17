/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:46:05 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 11:18:52 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150){}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	this->name = other.getGrade();
	this->grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string & Name, int gr) : name(Name){
	if (gr > 150)
		throw GradeToolLowException();
	if (gr < 1)
		throw GradeToolHighException();
	this->grade = gr;
}

const std::string Bureaucrat::getName() const{
	return (name);
}

int Bureaucrat::getGrade() const{
	return (grade);	
}

const char *Bureaucrat::GradeToolHighException::what() const throw(){
	return ("Grade is too high, the grade must be between 1 and 150.");}
const char *Bureaucrat::GradeToolLowException::what() const throw(){
	return ("Grade is too low, the grade must be between 1 and 150.");}

void Bureaucrat::incrementGrade(){
	if ((this->grade - 1) < 1)
		throw GradeToolHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade(){
	if ((this->grade + 1) > 150)
		throw GradeToolLowException();
	else	
		this->grade++;
}

void Bureaucrat::signForm(Form &form){
	try{
		form.beSigned(*this);
			std::cout <<this->getName()<<" signed "<<form.getName()<<"."<<std::endl;
	}
	catch(const std::exception& e){
		std::cout <<this->getName()<<" couldn't sign "<<form.getName()<<" because "<<e.what()<<"."<<std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat & mem){
	os<< mem.getName()<<", bureacrat grade "<<mem.getGrade()<<"."<<std::endl;
	return (os);
}