/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:47 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/10 18:30:23 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		const std::string Name;
		const std::string Target;
		const int gradeToSign;
		bool signedStatus;
		const int gradeToExecute;
	public:
		Form(const std::string &name_, int gradeToSign_, int gradeToExecute_);
		~Form();
		
		Form (const std::string &formForm, const std::string &target);

		const std::string &getName() const;

		bool getSignedStatus() const;

		int getGradeToSign() const;

		int getGradeToExecute() const;

		void beSigned(Bureaucrat const & other);
		
		class GradeToolHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeToolLowException: public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream  &operator<<(std::ostream & os, const Form & other);

# endif