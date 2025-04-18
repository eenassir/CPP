/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:46:11 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 18:52:55 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
		Bureaucrat amin("amin", 10);
		Form anas("anas", 60, 60);

		// std::cout <<amin<<std::endl;
		// std::cout <<anas<<std::endl;
        std::cout << anas.getSignedStatus() << std::endl;
		amin.signForm(anas);
        std::cout << anas.getSignedStatus() << std::endl;
    }
	catch (std::exception & e){
       std::cout << "Exception: " << e.what() << std::endl;	
	}
    return 0;
}