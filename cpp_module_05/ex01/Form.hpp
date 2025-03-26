/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:47 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/25 15:21:19 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string Name;
		bool signedStatus;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		Form(const std::string &name_, int gradeToSign_, int gradeToExecute_);
		~Form();
		
		const std::string &getName() const;

		bool getSignedStatus() const;

		int getGradeToSign() const;

		int getGradeToExecute() const;

		void beSigned(const Bureaucrat & other);
		
		class GradeToolHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeToolLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream  &operator<<(std::ostream & os, const Form & other);

# endif