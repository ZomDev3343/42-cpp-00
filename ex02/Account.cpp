/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:36:15 by tohma             #+#    #+#             */
/*   Updated: 2024/04/28 01:23:54 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <time.h>
#include <iostream>
#include <vector>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;	
}

/* --- Getters --- */

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

/* --- Getters --- */

/* --- Display --- */

void	Account::_displayTimestamp(void)
{
	time_t timer;
	struct tm	*timeinfo;

	time(&timer);
	timeinfo = localtime(&timer);
	std::cout << "[" << timeinfo->tm_year << timeinfo->tm_mon
	<< timeinfo->tm_mday << "_" << timeinfo->tm_hour << timeinfo->tm_min
	<< timeinfo->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "index:" << Account::_accountIndex;
}

/* --- Display --- */