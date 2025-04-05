/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:47 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/05 11:57:11 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string Name;
		bool signedStatus;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		AForm(const std::string &name_, int gradeToSign_, int gradeToExecute_);
		
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
		virtual void executeAForm(AForm const & form) const = 0;
};

std::ostream  &operator<<(std::ostream & os, const AForm & other);

# endif