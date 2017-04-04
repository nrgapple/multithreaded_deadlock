//
//  deadlocked.hpp
//  Project 2

#include <stdio.h>
#include <iostream>
#include <mutex>

using namespace std;

class Account
{
private:
  
  string name;
  double balance;
  mutex mutex_withdraw, mutex_deposit;
  
public:
  
  Account()
  {
    balance = 0;
    name = "Null";
  }
  
  Account(double _balance, string _name)
  {
    name = _name;
    balance = _balance;
  }
  
  void withdraw_bad(double amount)
  {
    lock_guard<mutex> g1(mutex_withdraw);
    lock_guard<mutex> g2(mutex_deposit);
    balance -= amount;
  }
  
  void deposit_bad(double amount)
  {
    lock_guard<mutex> g1(mutex_deposit);
    lock_guard<mutex> g2(mutex_withdraw);
    balance += amount;
  }
  
  double get_balance()
  {
    return balance;
  }
  
  string get_name()
  {
    return name;
  }
};
