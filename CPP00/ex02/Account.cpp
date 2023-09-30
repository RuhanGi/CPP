/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoltay <mgoltay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:16:06 by mgoltay           #+#    #+#             */
/*   Updated: 2023/08/07 19:59:19 by mgoltay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	time_t	now = time(0);
	tm	*ltm = localtime(&now);

	std::cout << "[" << (1900 + ltm->tm_year) << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon);
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mday;
	std::cout << "_" << std::setfill('0') << std::setw(2) << ltm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_min << ltm->tm_sec; 
	std::cout << "]";
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << "\n";
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = (Account::_nbAccounts++);
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created\n";
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed\n";
	Account::_nbAccounts--;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused\n";
		return (false);
	}
	std::cout << withdrawal;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << "\n";
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << "\n";
}
