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
        };
        
        float _liquidity;
        std::vector<Account> _clientAccounts;
    public:
    //  Constructors
        Bank();
        Bank(float);
        ~Bank();

    //  Member Functions
    
        void transfer(float &src, float &dest, float ammount);
    //  Setters
        void setLiquidity(float);
        void setClient(int);
    
    //  Getters
        const float &getLiquidity();
        const std::vector<Account> &getClients();

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

        const float &operator[](float);

    
        
        //  Friends
            // friend std::ostream &operator<<(std::ostream& , const Bank& );
        };

#endif