/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:46:05 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/18 00:41:02 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default_name"), grade(150){}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this == &other)
		return (*this);
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

const std::string& Bureaucrat::getName() const{
	return (name);
}

int Bureaucrat::getGrade() const{
	return (grade);	
}

const char *Bureaucrat::GradeToolHighException::what() const throw() {
	return ("Grade is too High");}
const char *Bureaucrat::GradeToolLowException::what() const throw(){
	return ("Grade is too Low");}

void Bureaucrat::incrementGrade(){
	if ((this->grade - 1) < 1)
		throw GradeToolHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade(){
	if ((this->grade + 1) > 150)
		throw GradeToolLowException();		
	this->grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat & mem){
	os<< mem.getName()<<", bureacrat grade "<<mem.getGrade()<<"."<<std::endl;
	return (os);
}