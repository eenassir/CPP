/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:46:11 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/23 16:00:01 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "==== Testing Bureaucrat Class ====" << std::endl;

    std::cout << "\nTest 1: Valid construction" << std::endl;
    try {
        Bureaucrat john("John", 75);
        std::cout << john << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 2: Grade too high (0)" << std::endl;
    try {
        Bureaucrat bob("Bob", 0);
        std::cout << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 3: Grade too low (151)" << std::endl;
    try {
        Bureaucrat alice("Alice", 151);
        std::cout << alice << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 4: Increment grade" << std::endl;
    try {
        Bureaucrat dave("Dave", 10);
        std::cout << "Before increment: " << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 5: Decrement grade" << std::endl;
    try {
        Bureaucrat carol("Carol", 140);
        std::cout << "Before decrement: " << carol << std::endl;
        carol.decrementGrade();
        std::cout << "After decrement: " << carol << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 6: Increment at limit (grade 1)" << std::endl;
    try {
        Bureaucrat frank("Frank", 1);
        std::cout << "Before increment: " << frank << std::endl;
        frank.incrementGrade();
        std::cout << "After increment: " << frank << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 7: Decrement at limit (grade 150)" << std::endl;
    try {
        Bureaucrat grace("Grace", 150);
        std::cout << "Before decrement: " << grace << std::endl;
        grace.decrementGrade();
        std::cout << "After decrement: " << grace << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}