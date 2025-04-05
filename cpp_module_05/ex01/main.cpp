/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:46:11 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/04 11:04:14 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
		Bureaucrat amin("amin", 50);
		Form anas("anas", 60, 60);

		std::cout <<amin<<std::endl;
		std::cout <<anas<<std::endl;
		amin.signForm(anas);
		std::cout <<amin<<std::endl;
		std::cout <<anas<<std::endl;
		
        Bureaucrat high("Executive", 1);
        Bureaucrat mid("Manager", 75);
        Bureaucrat low("Intern", 150);

        Form easyForm("Simple Request", 100, 150);
        Form mediumForm("Budget Approval", 50, 30);
        Form hardForm("Top Secret Clearance", 5, 1);

        std::cout << easyForm << std::endl;
        low.signForm(easyForm);
        std::cout << easyForm << std::endl;

        std::cout << mediumForm << std::endl;
        low.signForm(mediumForm);  
        mid.signForm(mediumForm);
        std::cout << mediumForm << std::endl;

        std::cout << hardForm << std::endl;
        mid.signForm(hardForm);
        high.signForm(hardForm);
        std::cout << hardForm << std::endl;
    }
	catch (std::exception & e){
       std::cout << "Exception: " << e.what() << std::endl;	
	}
    return 0;
}