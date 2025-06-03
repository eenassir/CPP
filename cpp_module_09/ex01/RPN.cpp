/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:21:59 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/30 09:49:57 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <climits>

int RPN::parce_input(std::string str, std::list<std::string> &strs)
{
	for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '(' || str[i] == ')')
        {
            std::cerr<<"Error"<<std::endl;
            return (1);
        }
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '+' \
		&& str[i] != '-' && str[i] != '*' && str[i] != '/')
        {
            std::cerr<<"Error"<<std::endl;
            return (1);
        }
    }
    std::stringstream stream(str);
    std::string buffer;
    for (;stream >> buffer;)
    {
        strs.push_back(buffer);
    }
    if (strs.empty())
    {
        std::cerr<<"Error"<<std::endl;
        return (1);
    }
    std::list<std::string>::iterator list_iter;
    list_iter = strs.begin();
    for (;list_iter != strs.end(); list_iter++)
    {
        std::string &tmp = *list_iter;
        if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/")
            continue ;
        else
        {
            bool flag =true;
			int i = 0;
            for (;tmp[i];i++)
            {
                if (!(tmp[i] >= '0' && tmp[i] <= '9'))
                {
                    flag =false;
                    break ;
                }
                if (!flag)
                {
                    std::cerr<<"Error"<<std::endl;
                    return (1);
                }
            }
        }
    }
	return (0);
}

int RPN::rpn(std::list<std::string> &strs, std::stack<int> &holder)
{
	std::list<std::string>::iterator iter;
    iter = strs.begin();
    for (; iter != strs.end(); iter++)
    {
        std::string &tmp = *iter;

        if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/")
        {
            if (holder.size() < 2)
            {
                std::cerr<<"Error"<<std::endl;
                return (1);
            }
            int top_b = holder.top(); holder.pop();
            int top_a = holder.top(); holder.pop();
            int res;
            if (tmp == "+")
            {
                if ((top_b > 0 && top_a > INT_MAX - top_b) || (top_b < 0 && top_a < INT_MIN - top_b))
                {
                    std::cout <<"Error"<<std::endl;
                    return (1);
                }
                res = top_a + top_b;
            }
            else if (tmp == "-")
            {
                if ((top_b < 0 && top_a > INT_MAX + top_b) && (top_b > 0 && top_a < INT_MIN + top_b))
                {
                    std::cout <<"Error"<<std::endl;
                    return (1);
                }
                res = top_a - top_b;
            }
            else if (tmp == "*")
            {
                if (top_a != 0 && top_b != 0)
                {
                    if ((top_a > 0 && top_b > 0 && top_a > INT_MAX / top_b) ||
                        (top_a > 0 && top_b < 0 && top_b < INT_MIN / top_a) ||
                        (top_a < 0 && top_b > 0 && top_a < INT_MIN / top_b) ||
                        (top_a < 0 && top_b < 0 && top_a < INT_MAX / top_b))
                    {
                        std::cerr << "Error" << std::endl;
                        return (1);
                    }
                }
                res = top_a * top_b;
            }
            else if (tmp == "/")
            {
                if (top_b == 0)
                {
                    std::cerr<<"Error"<<std::endl;
                    return (1);
                }
                if (top_a == INT_MIN && top_b == -1)
                {
                    std::cerr << "Error" << std::endl;
                    return (1);
                }
                res = top_a / top_b;
            }
            holder.push(res);
        }
        else
        {
            int num = 0;
            for (size_t j = 0; tmp[j]; j++)
                num = num * 10 + tmp[j] - 48;
            if (num >= 10)
            {
                std::cerr<<"Error"<<std::endl;
                return (1);
            }
            holder.push(num);
        }
    }
	return (0);
}