/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:57:43 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/23 09:26:14 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Account.hpp"
#include <cstdbool>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int deposit)
{
	if (deposit == -1)
		return ;
	_amount = deposit;
	_totalAmount += deposit;
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout <<"index:"<<_accountIndex <<";amount:"<< _amount <<";created\n";
}

int Account::getNbAccounts(void){return (_nbAccounts);}
int Account::getTotalAmount(void){return (_totalAmount);}
int Account::getNbDeposits(void){return (_totalNbDeposits);}
int Account::getNbWithdrawals(void){return (_totalNbWithdrawals);}

void Account::displayAccountsInfos(void)
{
	std::cout << "accounts:"<<Account::getNbAccounts()<<";";
	std::cout <<"total:"<<Account::getTotalAmount() <<";";
	std::cout <<"deposits:"<<Account::getNbDeposits()<<";";
	std::cout <<"withrawals:"<<Account::getNbWithdrawals()<<"\n";
}
Account::~Account(void)
{
	std::cout <<"dd\n";	
}

bool Account::makeWithdrawal(int withrawal)
{
	if (withrawal != 0)
		return (1);
	return (0);
}
void Account::makeDeposit(int deposit){_nbDeposits = deposit, _totalNbDeposits += deposit;}
int Account::checkAmount(void) const {return (_amount);}
void Account::_displayTimestamp(void){std::cout <<"time\n";}
void Account::displayStatus(void) const
{
	std::cout<<"index:"<<_accountIndex<<";";
	std::cout<<"amount:"<<_amount<<";";
	std::cout<<"deposits"<<_nbDeposits<<";";
	std::cout<<"withrawals:"<<_nbWithdrawals<<"\n";
}