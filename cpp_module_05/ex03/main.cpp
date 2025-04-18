/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:46:11 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/18 09:27:58 by eenassir         ###   ########.fr       */
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
        Bureaucrat low("Intern", 70);

        
        Intern intern;
        AForm *rrf;

        rrf = intern.makeForm("robotomy request", "Bender");
        std::cout<<*rrf<<std::endl;
        low.signForm(*rrf);
        std::cout <<std::endl;
        std::cout<<*rrf<<std::endl;
        delete(rrf);

    } catch (std::exception& e) {
        std::cout << "The thrown exception: " << e.what() << std::endl;
    }
    return 0;
}