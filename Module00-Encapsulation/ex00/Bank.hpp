#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include "Account.hpp"

class Bank {
    private:
        unsigned int _liquidity;
        std::vector<Account> _clientAccounts;
        
    public:
    //  Constructors
        Bank();
        ~Bank();

    //  Setters
    void setLiquidity(unsigned int);
    void setClient(const Account &);
    //  Getters

    const unsigned int &getLiquidity();
    const Account &getClient();
    //  Friends
        friend std::ostream& operator << (std::ostream& , const Bank& );
};

#endif