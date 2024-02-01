/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:00:19 by jschott           #+#    #+#             */
/*   Updated: 2023/12/18 15:40:51 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <locale>

int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account:: _displayTimestamp ();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp ();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	if (withdrawal > this->checkAmount())
	{	std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;	
	return true;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp ();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl; 
}

void	Account::_displayTimestamp( void ){
	time_t	timestamp;

	timestamp = time(NULL);
	std::tm timestamp_zone = *localtime(&timestamp);
	std::cout 	<< "[" 
				<< timestamp_zone.tm_year  + 1900
				<< std::setfill('0') << std::setw(2) << timestamp_zone.tm_mon + 1
				<< std::setfill('0') << std::setw(2) << timestamp_zone.tm_mday << "_"
				<< std::setfill('0') << std::setw(2) << timestamp_zone.tm_hour
				<< std::setfill('0') << std::setw(2) << timestamp_zone.tm_min
				<< std::setfill('0') << std::setw(2) << timestamp_zone.tm_sec
				<< "] ";
	return ;
}

Account::Account( int initial_deposit ) {
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp ();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" <<this->checkAmount() << ";";
	std::cout << "created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account( void )
{
	Account::_displayTimestamp ();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed" << std::endl;
	return ;
}


