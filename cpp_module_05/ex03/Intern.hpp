/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:07:01 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/10 16:40:25 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "Form.hpp"
#include <stdexcept>

class Intern
{
	public:
		class FormExistException : public std::exception
		{
			public:
			const char *what() const throw();
		};
		Form* makeForm(const std::string &formName, const std::string &target);
};

#endif