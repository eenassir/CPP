/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:36:05 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/14 15:41:40 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <iostream>

	struct Data
	{
		public:
			int a;
			float b;
			char c;
			std::string other;
			Data(int mem1, float mem2, char mem3, std::string mem4);
	};

#endif