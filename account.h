#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include <time.h>
struct Name {
    Name(std::string f_name = "**FirstName**", std::string l_name = "**LastName**")
        : first_name(f_name), last_name(l_name)
    {};
    std::string first_name;
    std::string* middle_name;
    std::string  last_name;
};

std::string date_string(const tm&);

class Account {

private:
    Name full_name;
    long long int account_number;
    time_t date;
    bool activated;
    double balance;

public:
    Account();
    Account(Name&);
    Account(Name&, int, time_t, double, bool);
    ~Account();
    bool is_active() const;
    bool deposit(double);
    bool withdraw(double);
    bool is_richer(Account&);          // sorting rich-poor
    friend int save(Account&);
    Account operator+(Account&);        // for counting all deposits  
    void print_info() const;
    double get_amount() const;
};

#endif /* ACCOUNT_H */