/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:46:11 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/10 16:38:15 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main()
{

    try {
        Bureaucrat low("Intern", 140);
        Bureaucrat mid("Officer", 70);
        Bureaucrat high("Director", 5);

        std::cout << low << std::endl;
        std::cout << mid << std::endl;
        std::cout << high << std::endl;

        Intern intern;
        Form *form;

        form = intern.makeForm("form", "target");
    
        ShrubberyCreationForm shrubForm("garden");
        std::cout << shrubForm << std::endl;

        low.signForm(shrubForm);
        low.executeForm(shrubForm);

        while (low.getGrade() > 145) {
            low.incrementGrade();
        }
        std::cout << low << std::endl;
        low.signForm(shrubForm);
        
        low.executeForm(shrubForm);

        mid.executeForm(shrubForm);
        RobotomyRequestForm robotForm("Bender");
        std::cout << robotForm << std::endl;
        
        low.signForm(robotForm);

        mid.signForm(robotForm);
        
        mid.executeForm(robotForm);

        high.executeForm(robotForm);
        
        PresidentialPardonForm pardonForm("Arthur Dent");
        std::cout << pardonForm << std::endl;

        mid.signForm(pardonForm);

        high.signForm(pardonForm);
        
        Bureaucrat executive("Executive", 10);
        std::cout << executive << std::endl;
        executive.executeForm(pardonForm);
        
        high.executeForm(pardonForm);

    } catch (std::exception& e) {
        std::cerr << "The thrown exception: " << e.what() << std::endl;
    }

    return 0;
}