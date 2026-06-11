#ifndef BANK_HPP
#define BANK_HPP

#include <exception>
#include <iostream>
#include <map>
#include <algorithm>
#include <ctime>


class Bank {

    private:
        class Account {
            private:
            //Attributes
                float _value;
                
            public:
                //Constructors    
                Account();
                Account(float);
                ~Account();
                //Getters
                const float &getValue(void) const;
                void setValue(float);
        };
        
        float _liquidity;
        std::map<int ,Account> _clientAccounts;
        
        // Member functions
        void setLiquidity(float);
        void setClient(float);
    public:
    //  Constructors
        Bank(float);
        ~Bank();

    //  Member Functions
    
        void createAccount(float);
        void transfer(int src, int dest, float ammount);
        void deleteAccount(int id);
        void loanMoney(int id, float ammount);
    //  Setters
    //  Getters
         float &getLiquidity();
        const std::map<int, Account> &getClients();

    //  Exception
       
        class NegativeValueException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class NotEnoughBalanceException : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        
        class AccountDoesNotExistException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class NoAccountsInBank : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class BankIsFull : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        const float &operator[](int);
};

#endif