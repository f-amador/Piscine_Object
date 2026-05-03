#include "Account.hpp"

Account::Account(): _id(0), _value(0) {
    std::cout << "Account default constructor called" << std::endl;
}

Account::~Account(){
    std::cout << "Account destructor called" << std::endl;
}

void Account::setId(unsigned int id) {
    _id = id;
}

void Account::setValue(unsigned int value) {
    _value = value;
}

const unsigned int &Account::getId(void) {
    return (_id);
}

const unsigned int &Account::getValue(void) {
    return (_value);
}

std::ostream &operator<<(std::ostream &p_os, const Account &p_account) {
    p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
	return (p_os);
}