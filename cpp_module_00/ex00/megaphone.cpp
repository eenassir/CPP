/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:12:34 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/21 13:39:30 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string str;

int main(int ac, char **av)
{
    if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
    for (int i = 1; i < ac; i++)
    {
		str = av[i];
        for (size_t j = 0; j < str.length(); j++)
            std::cout << (unsigned char)std::toupper(str[j]);
        (i < ac - 1) && (std::cout << " ");
    }
    std::cout << std::endl;
    return (0);
}
