/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:46:08 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 18:49:31 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include "Form.hpp"
#include <string>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		Bureaucrat(const std::string & Name, int gr);
		const std::string getName() const;
		int getGrade() const;
		class GradeToolHighException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		class GradeToolLowException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
		void incrementGrade();
		void decrementGrade();
		void signForm(Form & form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat & mem);

# endif