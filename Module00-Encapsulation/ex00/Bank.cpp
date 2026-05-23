#include "Bank.hpp"


Bank::Account::Account(): _id(0), _value(0) {
    std::cout << "Account default constructor called" << std::endl;
}

Bank::Account::Account(float id): _id(id), _value(0) {
    std::cout << "Account parameter(float) constructor called" << std::endl;
}

Bank::Account::~Account(){
    std::cout << "Account destructor called" << std::endl;
}

// void Account::setId(float id) {
//     _id = id;
// }

// void Account::setValue(float value) {
//     _value = value;
// }

const float &Bank::Account::getId(void) const {
    return (_id);
}

const float &Bank::Account::getValue(void) const {
    return (_value);
}

// std::ostream &operator<<(std::ostream &p_os, const Bank::Account p_account) {
//     p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
// 	return (p_os);
// }

// Constructors
Bank::Bank(): _liquidity(0), _clientAccounts(std::vector<Account>()) {
    std::cout << "Bank default constructor called" << std::endl;
}

Bank::Bank(float liquidity): _clientAccounts(std::vector<Account>()) {
	if (liquidity <= 0)
		throw NegativeValueException();
	std::cout << "Bank parameter(float) constructor called" << std::endl;
} 

Bank::~Bank() {
    std::cout << "Bank default destructor called" << std::endl;
}

// //Member Functions 
// void Bank::transfer(float &src, float &dest, float ammount) {
// 	if (ammount <= 0) {
// 		throw NegativeValueException();
// 	}
// 	if ((*this)[0] < ammount)
// 	{
// 		throw NotEnoughBalanceException();
// 	}
// }


// Setters
void Bank::setLiquidity(float liquidity) {
    _liquidity = liquidity;
}

void Bank::setClient(int id)
{
	for (std::vector<Account>::const_iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it ++)
	{
		if (id == (*it).getId())
		{
			throw DuplicateIdException();
		}
	}
	_clientAccounts.push_back(Bank::Account(id));
}
// Getters

const float &Bank::getLiquidity() {
	return _liquidity;
}

const std::vector<Bank::Account> &Bank::getClients() {
	return _clientAccounts;
}

//Exceptions
const char *Bank::DuplicateIdException::what() const throw() {
	return "Account Id already exists";
}

const char *Bank::NegativeValueException::what() const throw() {
	return "Cannot accept Negative or Zero value";
}

const char *Bank::NotEnoughBalanceException::what() const throw() {
	return "Insuficient ";
}

// Friends
// std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
// 		p_os << "Bank informations : " << std::endl;
// 		p_os << "Liquidity : " << p_bank._liquidity << std::endl;
// 		for (std::vector<Bank::Account>::const_iterator it = p_bank._clientAccounts.begin(); it != p_bank._clientAccounts.end(); ++it)
// 			p_os << *it << std::endl;
// 		return (p_os);
// }
const float &Bank::operator[](float id) {
	try {
		if ( id <= 0)
			throw NegativeValueException();
		return (_clientAccounts[id].getValue());
	}
	catch (std::exception &e)
	{
		std::cout << "HERE";
		throw e.what();
	}
}