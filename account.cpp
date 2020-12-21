#include "account.h"
#include <stdlib.h>
#include <iomanip>



Account::Account(Name& new_name) 
{
    srand(time(0));
    full_name = new_name;
    account_number = rand()*rand() % 1000,000,000;
    date = time(0);
    balance = 0.0;
}

bool Account::is_active() const
{
    return activated;
}

bool Account::deposit(double load)
{
    activated = true;
    if(load > 0.0){
        balance += load;
        return true;
    }
    return false;
}

bool Account::withdraw(double load)
{
    if(load < 0.0){
        return false;
    }
    double final_amount = balance - load;
    if(final_amount < 0){
        return 0;
    }
    balance = final_amount;
    return true;
}

bool Account::is_richer(Account& other)
{
    if(!activated){
        std::cout << "Please deposit to activate your account.\n";
    }
    return (this->balance < other.balance);
}

double Account::get_amount() const
{
    return balance;
}

void Account::print_info() const
{
    char date_str[50];
    strftime(date_str, 40,"%Y-%m-%d %H:%M",localtime(&date));
    std::cout << "\nAccount holder name : " << full_name.first_name << " " << full_name.last_name;
    std::cout << "\nRemaining balance   : " << this->balance;
    std::cout << "\nAccount Number      : " << this->account_number;
    std::cout << "\nActive status       : " << (this->activated ? "Active" : "Inactive");
    std::cout << "\nDate Created        : " << date_str;
    std::cout << "\n";
}