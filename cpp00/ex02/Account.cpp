#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::Account() {}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << checkAmount() - deposit << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << checkAmount() << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	bool flag = true;
	int p_amount = checkAmount();

	if (p_amount - withdrawal < 0)
		flag = false;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" ; 
	if (flag)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << "amount:" << checkAmount() << ";"
					<< "nb_withdrawals:" << _nbWithdrawals ;
	}
	else
		std::cout << "withdrawal:refused";
	std::cout << std::endl;
	return flag;
}

int Account::checkAmount() const 
{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t current = std::time(NULL);
	std::tm *ptm = std::localtime(&current);
	char timestamp[20];

	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", ptm);
	std::cout << timestamp << " ";
}
