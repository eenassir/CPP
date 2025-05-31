/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:21:56 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/30 09:49:45 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <sstream>
#include <iomanip>

class RPN
{
    private:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
    public:
        static int parce_input(std::string str, std::list<std::string> &strs);
        static int rpn(std::list<std::string> &strs, std::stack<int> &holder);
};

#endif