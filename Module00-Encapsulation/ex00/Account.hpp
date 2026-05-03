#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
    private:
        unsigned int _id;
        unsigned int _value;

    public:
    //  Constructors    
        Account();
        ~Account();
    
    //  Member Functions
    
    //  Setters    
        void setId(unsigned int);
        void setValue(unsigned int);
    
    //Getters
        const unsigned int &getId(void);
        const unsigned int &getValue(void);
	    friend std::ostream &operator<<(std::ostream& , const Account& );
};

#endif