/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:07:01 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 23:42:32 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Form.hpp"
#include <stdexcept>
#include <string>

class Intern
{
	private:
		struct FormType
		{
			std::string name;
			AForm *(*create)(const std::string &target);
		};
		static FormType formType[3];
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		class FormExistException : public std::exception{
			public:
			const char *what() const throw();
		};
		AForm* makeForm(const std::string &formName, const std::string &target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif