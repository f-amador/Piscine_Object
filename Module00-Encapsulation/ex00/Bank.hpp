#ifndef BANK_HPP
#define BANK_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Account.hpp"

class Bank {
    private:
        unsigned int _liquidity;
        std::vector<Account> _clientAccounts;
        
    public:
    //  Constructors
        Bank();
        Bank(unsigned int);
        ~Bank();

    //  Member Functions
    
    
    //  Setters
        void setLiquidity(unsigned int);
        void setClient(const Account &);
    
    //  Getters
        const unsigned int &getLiquidity();
        const Account &getClient();

    //  Exception
        class DuplicateIdException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

    //  Friends
        friend std::ostream& operator << (std::ostream& , const Bank& );
};

#endif