#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Initialize class static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
// [19920104_091532] index:5;amount:0;created
Account::Account(int initial_deposit) 
{
  _accountIndex = _nbAccounts;
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  _nbAccounts++;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor
// [19920104_091532] index:0;amount:47;closed
Account::~Account(){
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// [19920104_091532]
void  Account::_displayTimestamp()
{
  std::time_t t = std::time(0);   // Get the time now
  std::tm* now = std::localtime(&t);
  std::cout << '[' << (now->tm_year + 1900) 
            << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) 
            << std::setw(2) << now->tm_mday << '_' 
            << std::setw(2) << now->tm_hour 
            << std::setw(2) << now->tm_min 
            << std::setw(2) << now->tm_sec << ']';
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
  _displayTimestamp();
  std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;

}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
  int oldAmount = _amount;
  _displayTimestamp();
  _nbDeposits++;
  _amount += deposit;
  _totalNbDeposits++;
  _totalAmount += deposit;
  std::cout << " index:" << _accountIndex << ";p_amount:" << oldAmount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// [19920104_091532] index:5;p_amount:23;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
  _displayTimestamp();
  int oldAmount = _amount;
  std::cout << " index:" << _accountIndex << ";p_amount:" << oldAmount;
  if (checkAmount() < withdrawal)
  {
    std::cout << ";withdrawal:refused" << std::endl;
    return false;
  }
  _nbWithdrawals++;
  _amount -= withdrawal;
  _totalNbWithdrawals++;
  _totalAmount -= withdrawal;
  std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

int		Account::checkAmount( void ) const
{
  return _amount;
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}


// Getters
int	Account::getNbAccounts( void )
{
  return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
  return _totalAmount;
}

int	Account::getNbDeposits( void )
{
  return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
  return _totalNbWithdrawals;
}