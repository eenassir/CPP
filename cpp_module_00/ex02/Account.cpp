/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:57:43 by eenassir          #+#    #+#             */
/*   Updated: 2025/01/25 13:46:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Account.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int deposit)
{
	_amount = deposit;
	_totalAmount += deposit;
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex <<";amount:"<< _amount <<";created\n";
}

int Account::getNbAccounts(void){return (_nbAccounts);}
int Account::getTotalAmount(void){return (_totalAmount);}
int Account::getNbDeposits(void){return (_totalNbDeposits);}
int Account::getNbWithdrawals(void){return (_totalNbWithdrawals);}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:"<<Account::getNbAccounts()<<";";
	std::cout <<"total:"<<Account::getTotalAmount() <<";";
	std::cout <<"deposits:"<<Account::getNbDeposits()<<";";
	std::cout <<"withdrawals:"<<Account::getNbWithdrawals()<<"\n";
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";";
	std::cout<<"amount:"<<_amount<<";";
	std::cout<<"closed\n";
}

bool Account::makeWithdrawal(int withrawal)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";";
	std::cout<<"p_amount:"<<_amount<<";";
	std::cout<<"withdrawal:";
	if (withrawal > _amount)
	{
		std::cout<<"refused\n";
		return (1);
	}
	std::cout<<withrawal<<";";
	_amount -= withrawal;
	_totalAmount -= withrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout<<"amount:"<<_amount<<";";
	std::cout<<"nb_withdrawals:"<<_nbWithdrawals;
	std::cout<<"\n";
	return (0);
}
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";";
	std::cout<<"p_amount:"<<_amount<<";";
	std::cout<<"deposit:"<<deposit<<";";
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout<<"amount:"<<_amount<<";";
	std::cout<<"nb_deposits:"<<_nbDeposits<<"\n";

}
int Account::checkAmount(void) const {return (_amount);}
void Account::_displayTimestamp(void)
{
	std::time_t time_now = std::time(nullptr);
	std::tm* time_local = std::localtime(&time_now);
	std::ostringstream timestamp;
	timestamp << std::setfill('0') << (time_local->tm_year + 1900)
	<< std::setw(2) << (time_local->tm_mon + 1)
	<< std::setw(2) << (time_local->tm_mday) << "_"
	<< std::setw(2) << (time_local->tm_hour)
	<< std::setw(2) << (time_local->tm_min)
	<< std::setw(2) << (time_local->tm_sec);
	std::cout << "["<<timestamp.str() <<"] ";
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";";
	std::cout<<"amount:"<<_amount<<";";
	std::cout<<"deposits:"<<_nbDeposits<<";";
	std::cout<<"withdrawals:"<<_nbWithdrawals<<"\n";
}