/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:34:52 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/12 12:06:24 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static bool isChar(const std::string & literale);
		static bool isInt(const std::string & literale);
		static bool isFloat(const std::string & literale);
		static bool isDouble(const std::string & literale);
		static bool isPseudoLiterale(const std::string & literale);

		static void handlePseudoLiterale(const std::string &literale);
		static void convertToChar(char value);
		static void convertToInt(int value);
		static void convertToFloat(float value);
		static void convertToDouble(double value);
	public:
		static void convert(const std::string &toConvert);
};

#endif