/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:17:51 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/05 11:00:11 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : grade_to_sign(145), grade_to_exec(137)
{
	std::ofstream outfile(target + "_shruberry");
	if (outfile.is_open())
	{
		outfile<<"                 /\\"<<std::endl;
		outfile<<"                /@@\\"<<std::endl;
		outfile<<"               /@@@@\\"<<std::endl;
		outfile<<"              /@@@@@@\\"<<std::endl;
		outfile<<"             /@@@@@@@@\\"<<std::endl;
		outfile<<"            /@@@@@@@@@@\\"<<std::endl;
		outfile<<"           /@@@@@@@@@@@@\\"<<std::endl;
		outfile<<"                |#|     "<<std::endl;
		outfile<<"                |#|     "<<std::endl;
		outfile<<"________________|#|____________"<<std::endl;
		outfile<<"_______________________________"<<std::endl;
		outfile<<"                       "<<std::endl;
		outfile<<"                       "<<std::endl;
		outfile<<"                       "<<std::endl;
		outfile<<"              @@@@%@@@@@"<<std::endl;
		outfile<<"            @@@@@@@@@@@@@"<<std::endl;
		outfile<<"           @@@@@@@@@@@@@@@"<<std::endl;
		outfile<<"          @@@@@|@@|@@@@@@@@"<<std::endl;
		outfile<<"         @@@@@\\/@|@\\|@/@@@@@"<<std::endl;
		outfile<<"          @@@@@\\@|@@\\/@@@@@"<<std::endl;
		outfile<<"           @@@@@\\|@/@@@@@"<<std::endl;
		outfile<<"             @@@@|%|@@@@  "<<std::endl;
		outfile<<"                 |#|      "<<std::endl;
		outfile<<"                 |#|      "<<std::endl;
		outfile<<"                 |#|      "<<std::endl;
		outfile<<"                 |#|      "<<std::endl;
		outfile<<"_________________|#|_______________"<<std::endl;
		outfile<<"____________________________________"<<std::endl;
		outfile.close();
	}
	else
		std::cout <<"can't open the file"<<std::endl;

}