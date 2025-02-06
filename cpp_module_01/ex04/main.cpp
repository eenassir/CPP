/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:47:34 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/31 18:23:12 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

std::string replaceString(std::string& line, std::string& s1, std::string& s2)
{
	std::string result;
	size_t p = 0, prp = 0;

	while ((p = line.find(s1, prp)) != std::string::npos)
	{
		result.append(line, prp, p - prp);
		result.append(s2);
		prp = p + s1.length();
	}
	result.append(line, prp, std::string::npos);
	return (result);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cerr<<"Error usage: "<<av[0]<<" <filename> <s1> <s2>\n",1);
	std::string filename = av[1], s1 = av[2], s2 = av[3];
	
	// if (s1.length() != s2.length())
	// 	return (std::cerr <<"<s1> and <s2> not have the egale length\n", 1);
	std::ifstream infile(filename.c_str());
	if (!infile)
		return (std::cerr<<"Error: could not open the file"<<filename<<"\n", 1);
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
		return (infile.close(), std::cerr <<"Error usage: "<<(filename + ".replace").c_str()<<"\n", 1);
	std::string line;
	while (std::getline(infile, line))
	{
		std::string modifiedLine = replaceString(line, s1, s2);
		outfile << modifiedLine<<std::endl;
	}
	infile.close(), outfile.close();
	std::cout <<"Finished successfully\n";
	return (0);
}