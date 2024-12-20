/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:12:34 by eenassir          #+#    #+#             */
/*   Updated: 2024/12/13 00:38:33 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int j;

	i = 0;
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j] != '\0'){((av[i][j] >= 'a' && av[i][j] <= 'z')) && (av[i][j] -= 32);};
		std::cout << av[i];
	}
	return (0);
}
