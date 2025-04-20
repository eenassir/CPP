/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:35:11 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/20 09:50:04 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <sstream>
#include <string>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &other){
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other){
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isChar(const std::string &literale)
{
	return (literale.length() == 3 && literale[2] == '\'' && literale[0] == '\'');
}

bool ScalarConverter::isInt(const std::string &literale)
{
	std::string::size_type i = 0;
	if (literale[0] == '+' || literale[0] == '-')
		i++;
	for(; i < literale.length(); i++){
		if (!isdigit(literale[i]))
			return (0);
	}
	return (!literale.empty() && i > (literale[0] == '+' || literale[0] == '-' ? 1 : 0));
}

bool ScalarConverter::isFloat(const std::string &literale)
{
	if (literale == "nanf" || literale == "+inff" || literale == "-inff")
		return (true);
	if (literale.length() < 2 || literale[literale.length() - 1] != 'f')
		return (false);
	std::string withoutF = literale.substr(0, literale.length() - 1);
	std::stringstream iss(withoutF);
	double tmp;
	iss >> tmp;
	return (!iss.fail() && iss.eof());
}

bool ScalarConverter::isDouble(const std::string &literale)
{
	if (literale == "nan" || literale == "+inf" || literale == "-inf")
		return(true);
	std::stringstream iss(literale);
	double tmp;
	iss >> tmp;
	return (!iss.fail() && iss.eof());
}

bool ScalarConverter::isPseudoLiterale(const std::string &literale)
{
	return (literale == "nan" || literale == "nanf" || literale == "+inff" 
	|| literale == "+inf" || literale == "-inff" || literale == "-inf");
}


void ScalarConverter::handlePseudoLiterale(const std::string &literale)
{
	std::cout <<"char: impossible"<<std::endl;
	std::cout <<"int: impossible"<<std::endl;

	if (literale == "nanf" || literale == "nan")
	{
		std::cout <<"float: nanf"<<std::endl;
		std::cout <<"double: nan"<<std::endl;
	}
	else if(literale == "+inff" || literale == "+inf")
	{
		std::cout <<"float: +inff"<<std::endl;
		std::cout <<"double: +inf"<<std::endl;
	}
	else if(literale == "-inff" || literale == "-inf")
	{
		std::cout <<"float: -inff"<<std::endl;
		std::cout <<"double: -inf"<<std::endl;
	}
}

void ScalarConverter::convertToChar(char value)
{
	std::cout <<"char: ";
	if (isprint(value) != 0)
		std::cout <<"'"<<value<<"'"<<std::endl;
	else
		std::cout <<"Non displayable"<<std::endl;
std::cout <<"int: "<<static_cast<int>(value)<<std::endl;
std::cout <<"float: "<<static_cast<float>(value)<<".0f"<<std::endl;
std::cout <<"double: "<<static_cast<double>(value)<<".0"<<std::endl;
}

void ScalarConverter::convertToInt(int value)
{
	std::cout <<"char: "; 
	if (value >= 0 && value <= 127)
	{	
		if (isprint(value))
			std::cout <<static_cast<char>(value)<<std::endl;
		else
			std::cout <<"Non displayable"<<std::endl;
	}
	else
		std::cout <<"impossible"<<std::endl;
	std::cout <<"int: "<<static_cast<int>(value)<<std::endl;
	std::cout <<"float: "<<static_cast<float>(value)<<".0f"<<std::endl;
	std::cout <<"double: "<<static_cast<double>(value)<<".0"<<std::endl;
}

void ScalarConverter::convertToFloat(float value)
{
	std::cout <<"char: "; 
	if (isnan(value) || isinf(value))
		std::cout <<"impossible"<<std::endl;
	if (value >= 0 && value <= 127)
	{	
		if (std::isprint(static_cast<int>(value)))
			std::cout <<"'"<<static_cast<char>(value)<<"'"<<std::endl;
		else
			std::cout <<"Non displayable"<<std::endl;
	}
	else
		std::cout <<"impossible"<<std::endl;
	std::cout <<"int: ";
	if (isnan(value) || isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout <<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(value)<<std::endl;
	
	std::cout <<"float: "<<static_cast<float>(value);
	if (value == static_cast<int>(value))
		std::cout <<".0";
	std::cout <<"f"<<std::endl;
	std::cout <<"double: "<<static_cast<double>(value);
	if (value == static_cast<int>(value))
		std::cout<<".0";
	std::cout<<std::endl;
}

void ScalarConverter::convertToDouble(double value)
{
	std::cout <<"char: ";
	if (isnan(value) || isinf(value))
		std::cout <<"impossible"<<std::endl;
	if (value >= 0 && value <= 127)
	{	
		if (isprint(value))
			std::cout <<"'"<<static_cast<char>(value)<<"'"<<std::endl;
		else
			std::cout <<"Non displayable"<<std::endl;
	}
	else
		std::cout <<"impossible"<<std::endl;
	
	std::cout <<"int: ";
	if (isnan(value) || isinf(value) || value > static_cast<double>(std::numeric_limits<int>::max()) || value < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout<<"impossible"<<std::endl;
	else
		std::cout <<static_cast<int>(value)<<std::endl;
	std::cout <<"float: ";
	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
		std::cout <<"impossible"<<std::endl;
	else
	{
		std::cout <<static_cast<float>(value);
		if (value == static_cast<int>(value))
			std::cout<<".0";
		std::cout <<"f"<<std::endl;
	}
	std::cout <<"double: "<<static_cast<double>(value);
	if (value == static_cast<int>(value))
		std::cout<<".0";
	std::cout <<std::endl;
		
}

void ScalarConverter::convert(const std::string &toConvert)
{
	if (isPseudoLiterale(toConvert))
		return (handlePseudoLiterale(toConvert));
	if (isChar(toConvert))
		return(convertToChar(toConvert[1]));
	if (isInt(toConvert))
	{
		std::stringstream tmp;
		int intValue;
		tmp << toConvert;
		tmp >> intValue;
		if (tmp.fail())
		{	
			std::cout <<"Error: Integer overflow or convertion error"<<std::endl;
			return;
		}
		convertToInt(intValue);
		return ;
	}
	if (isFloat(toConvert))
	{
		float floatValue;
		std::stringstream tmp;
		std::string hold;
		
		hold = toConvert.substr(0, toConvert.length() - 1);
		tmp << hold;
		tmp >> floatValue;
		if (tmp.fail())
		{
			std::cout <<"Error: Float convertion error"<<std::endl;
			return ;
		}
		convertToFloat(floatValue);
		return ;
	}
	if (isDouble(toConvert))
	{
		double doubleValue;
		std::stringstream tmp;
		
		tmp >> doubleValue;
		if (tmp.fail())
		{
			std::cout <<"Error: Double conversion error"<<std::endl;
			return ;
		}
		convertToDouble(doubleValue);
		return ;
	}
	else
		std::cout <<"Error: Unrecognized literale type"<<std::endl;
	
}