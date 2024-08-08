/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:00:19 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:01:10 by jschott          ###   ########.fr       */
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

/**
 * @brief Returns the total number of accounts.
 * @return int - The total number of accounts.
 */
int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

/**
 * @brief Returns the total amount across all accounts.
 * @return int - The total amount across all accounts.
 */
int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

/**
 * @brief Returns the total number of deposits made across all accounts.
 * @return int - The total number of deposits.
 */
int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

/**
 * @brief Returns the total number of withdrawals made across all accounts.
 * @return int - The total number of withdrawals.
 */
int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

/**
 * @brief Displays overall information about all accounts.
 * Displays the total number of accounts, total amount across all accounts, total deposits, and total withdrawals.
 */
void	Account::displayAccountsInfos( void )
{
	Account:: _displayTimestamp ();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/**
 * @brief Handles deposit operations for an account.
 * @param deposit int - The amount to be deposited into the account.
 * Adds the deposit amount to the account's balance, increments the account's deposit count, and updates the total amount and total deposits across all accounts.
 */
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

/**
 * @brief Attempts to withdraw a specified amount from the account.
 * @param withdrawal int - The amount to be withdrawn.
 * @return bool - True if the withdrawal was successful, false otherwise.
 * Checks if the withdrawal amount is available. If not, the withdrawal is refused. Otherwise, it deducts the amount from the account balance, increments the withdrawal count, and updates the total withdrawals and total amount across all accounts.
 */
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

/**
 * @brief Returns the current balance of the account.
 * @return int - The current account balance.
 */
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

/**
 * @brief Displays the current status of the account.
 * Shows the account index, current balance, number of deposits, and number of withdrawals.
 */
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp ();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl; 
}

/**
 * @brief Displays the current timestamp in a specific format.
 * Internal function used to prefix log messages with a timestamp.
 */
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

/**
 * @brief Initializes a new account with a given initial deposit.
 * @param initial_deposit int - The initial deposit amount.
 * Sets the initial deposit, initializes deposits and withdrawals to 0, assigns an account index based on the total number of accounts, and updates the total amount across all accounts.
 */
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

/**
 * @brief Cleans up the account object.
 * Displays a closing message with the account index and final balance.
 */
Account::~Account( void )
{
	Account::_displayTimestamp ();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed" << std::endl;
	return ;
}
