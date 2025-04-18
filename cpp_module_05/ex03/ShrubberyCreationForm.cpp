/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:17:51 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 23:55:04 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target(""){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	this->target = other.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target) : AForm("ShrubberyCreationForm", 145, 137), target(_target)
{}

std::string ShrubberyCreationForm::getTarget() const{
	return (target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() <= this->getGradeToExecute())
		throw GradeToolLowException();
	std::string strr = target + "_shruberry"; 
	std::ofstream outfile(strr.c_str());
	if (outfile.is_open())
	{
		outfile <<"                 /\\"<<std::endl;
		outfile <<"                /@@\\"<<std::endl;
		outfile <<"               /@@@@\\"<<std::endl;
		outfile <<"              /@@@@@@\\"<<std::endl;
		outfile <<"             /@@@@@@@@\\"<<std::endl;
		outfile <<"            /@@@@@@@@@@\\"<<std::endl;
		outfile <<"           /@@@@@@@@@@@@\\"<<std::endl;
		outfile <<"                |#|     "<<std::endl;
		outfile <<"                |#|     "<<std::endl;
		outfile <<"________________|#|____________"<<std::endl;
		outfile <<"_______________________________"<<std::endl;
		outfile <<"                       "<<std::endl;
		outfile <<"                       "<<std::endl;
		outfile <<"                       "<<std::endl;
		outfile <<"              @@@@%@@@@@"<<std::endl;
		outfile <<"            @@@@@@@@@@@@@"<<std::endl;
		outfile <<"           @@@@@@@@@@@@@@@"<<std::endl;
		outfile <<"          @@@@@|@@|@@@@@@@@"<<std::endl;
		outfile <<"         @@@@@\\/@|@\\|@/@@@@@"<<std::endl;
		outfile <<"          @@@@@\\@|@@\\/@@@@@"<<std::endl;
		outfile <<"           @@@@@\\|@/@@@@@"<<std::endl;
		outfile <<"             @@@@|%|@@@@  "<<std::endl;
		outfile <<"                 |#|      "<<std::endl;
		outfile <<"                 |#|      "<<std::endl;
		outfile <<"                 |#|      "<<std::endl;
		outfile <<"                 |#|      "<<std::endl;
		outfile <<"_________________|#|_______________"<<std::endl;
		outfile <<"____________________________________"<<std::endl;
		outfile.close();
	}
	else
		throw FileOpenException();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw(){
	return ("can't open the file.");
}

AForm *ShrubberyCreationForm::create(const std::string &target_)
{
	return (new ShrubberyCreationForm(target_));
}