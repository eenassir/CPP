/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:13:18 by eenassir          #+#    #+#             */
/*   Updated: 2025/04/29 16:09:50 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{	
	{
		MutantStack<int> mstack;
		
        mstack.push(5);
        mstack.push(17);
        
        std::cout << mstack.top() << std::endl;
        
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(555);
        mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		MutantStack<int>::const_iterator it1 = mstack.begin();
		MutantStack<int>::const_iterator ite1 = mstack.end();
		
		(void)it1;
		(void)ite1;

		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	
	std::cout <<"testing using the std::list" <<std::endl;
	
	{
		std::list<int> mstack;
		
        mstack.push_back(5);
        mstack.push_back(17);
        
        std::cout << mstack.back() << std::endl;
        
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(555);
        mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		std::list<int>::const_iterator it1 = mstack.begin();
		std::list<int>::const_iterator ite1 = mstack.end();
		
		(void)it1;
		(void)ite1;

		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}