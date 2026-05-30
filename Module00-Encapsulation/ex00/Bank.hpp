#ifndef BANK_HPP
#define BANK_HPP

#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>


class Bank {

    private:
        class Account {
            private:
            //Attributes
                float _id;
                float _value;
                public:
                Account();
                Account(float);
                ~Account();
                //  Constructors    
            //Getters
                const float &getId(void) const;
                const float &getValue(void) const;
                void setValue(float);
        };
        
        float _liquidity;
        std::vector<Account> _clientAccounts;
        
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
    //  Setters
    //  Getters
         float &getLiquidity();
        const std::vector<Account> &getClients();
        Account &getAccount(int id);

    //  Exception
        class DuplicateIdException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

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

        const float &operator[](int);

    
        
        //  Friends
            // friend std::ostream &operator<<(std::ostream& , const Bank& );
        };

#endif