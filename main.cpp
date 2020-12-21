#include "account.h"
#define accounts_db "sample_users.txt"

void line()
{
    std::cout << "\n---------BANK ACOUNTS MANAGER----------\n";
}

Account* get_account(std::regex querry)
{
    Account* temp = new Account;
    std::string line_str;
    std::fstream file;
    file.open(accounts_db, std::fstream::in|std::fstream::app);

    int count = 0;
    while (!file.eof() && count < 100)
    {
        std::getline(file, line_str);
        if(std::regex_match(line_str, querry)){
            std::cout << line_str << '\n';
        }
        count++;
    }
	    file.close();

    return temp;
}

int main(int argc, char** argv)
{
    line();
    std::regex find_one("some one|honest man");
    auto account = get_account(find_one);
    // account->get_account(accounts_db.c_str());
    std::cout << "Thanks for using our app!\n";
    line();

    return 0;
}