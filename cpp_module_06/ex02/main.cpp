/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:08:34 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/20 10:46:47 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "header.h"

int main()
{
	Base *randomBase = NULL;
	std::cout <<"identified by pointer : ";
	identify(randomBase);

	std::cout <<"identified by reference : ";
	identify(*randomBase);
}