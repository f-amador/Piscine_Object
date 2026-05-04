#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
    private:
    //Attributes
        unsigned int _id;
        unsigned int _value;

    //  Setters
        void setId(unsigned int);

    public:
    //  Constructors    
        Account();
        Account(unsigned int);
        ~Account();
    
    //  Member Functions
    
    //  Setters    
        void setValue(unsigned int);
    
    //Getters
        const unsigned int &getId(void) const;
        const unsigned int &getValue(void) const;
	    friend std::ostream &operator<<(std::ostream& , const Account& );
};

#endif