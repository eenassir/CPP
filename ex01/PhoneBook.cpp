/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:33:03 by eenassir          #+#    #+#             */
/*   Updated: 2024/12/14 12:24:20 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.hpp"

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

int main(int ac, char **av)
{
	PhoneBook phone;
	int i;
	char *buffer;
	size_t size = 0;
	FILE *fd = stdin;
	ssize_t kk;
	
	i = 0;
	while (getline(&buffer, &size, fd) > 0)
	{
	}
}
