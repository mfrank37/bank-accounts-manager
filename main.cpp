#include "account.h"

void line()
{
    std::cout << "\n---------BANK ACOUNTS MANAGER----------\n";
};

int main(int argc, char** argv)
{
    line();
    Name name;
    Account* my_account = new Account(name);
    my_account->deposit(100.25);
    my_account->print_info();

    std::cout << "Thanks for using our app!\n";
    line();

    return 0;
}