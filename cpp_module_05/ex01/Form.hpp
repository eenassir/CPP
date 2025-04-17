/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:47 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 12:04:04 by eenassir         ###   ########.fr       */
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
		std::string Name;
		bool signedStatus;
		int gradeToSign;
		int gradeToExecute;
	public:
		Form();
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		
		Form(const std::string &name_, int gradeToSign_, int gradeToExecute_);
		
		std::string getName() const;

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