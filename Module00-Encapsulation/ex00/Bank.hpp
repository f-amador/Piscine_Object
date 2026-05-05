#ifndef BANK_HPP
#define BANK_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Account.hpp"

class Bank {
    private:
        float _liquidity;
        std::vector<Account> _clientAccounts;
        
    public:
    //  Constructors
        Bank();
        Bank(float);
        ~Bank();

    //  Member Functions
    
        void transfer(const Account &src, const Account &dest, float ammount);
    //  Setters
        void setLiquidity(float);
        void setClient(const Account &);
    
    //  Getters
        const float &getLiquidity();
        const std::vector<Account> &getClients();

    //  Exception
        class DuplicateIdException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class NegativeValue : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        const Account &operator[](float);

    
    //  Friends
        friend std::ostream &operator<<(std::ostream& , const Bank& );
    };

#endif