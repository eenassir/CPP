/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:20:02 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/17 09:34:10 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		// std::string target;
	public:
		RobotomyRequestForm(std::string const &target);
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
		// ocf
};

#endif