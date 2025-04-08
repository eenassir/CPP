/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:17:51 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/07 16:20:52 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target) : AForm("ShrubberyCreationForm", 145, 137), target(_target){
}

std::string ShrubberyCreationForm::getTarget() const{
	return (target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!getSignedStatus())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeToolLowException();
	std::ofstream outfile(target + "_shruberry");
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