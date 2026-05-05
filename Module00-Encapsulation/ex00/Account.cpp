#include "Account.hpp"

Account::Account(): _id(0), _value(0) {
    std::cout << "Account default constructor called" << std::endl;
}

Account::Account(float id): _id(id), _value(0) {
    std::cout << "Account parameter(float) constructor called" << std::endl;
}

Account::~Account(){
    std::cout << "Account destructor called" << std::endl;
}

// void Account::setId(float id) {
//     _id = id;
// }

// void Account::setValue(float value) {
//     _value = value;
// }

const float &Account::getId(void) const {
    return (_id);
}

const float &Account::getValue(void) const {
    return (_value);
}

std::ostream &operator<<(std::ostream &p_os, const Account &p_account) {
    p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
	return (p_os);
}