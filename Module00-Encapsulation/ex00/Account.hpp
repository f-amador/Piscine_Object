#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
    private:
    //Attributes
        float _id;
        float _value;

    //  Setters
        //void setId(float);

    public:
    //  Constructors    
        Account();
        Account(float);
        ~Account();
    
    //  Member Functions
    
    //  Setters    
        //void setValue(float);
    
    //Getters
        const float &getId(void) const;
        const float &getValue(void) const;
	    friend std::ostream &operator<<(std::ostream& , const Account& );
};

#endif