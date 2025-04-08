/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:47 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/07 12:23:29 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string  Name;
		bool               SignedStatus;
		const int          GradeToSign;
		const int          GradeToExecute;
	public:
		AForm();
		
		AForm(const std::string &name_, int gradeToSign_, int gradeToExecute_);

		virtual ~AForm();
		const std::string &getName() const;

		bool getSignedStatus() const;

		int getGradeToSign() const;

		int getGradeToExecute() const;

		void beSigned(Bureaucrat const & other);
		
		virtual void execute(Bureaucrat const & executor) const = 0;
		
		class GradeToolHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeToolLowException: public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception{
			public:
				const char *what() const throw();
		};
};

std::ostream  &operator<<(std::ostream & os, const AForm & other);

# endif