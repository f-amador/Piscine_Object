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

void Bank::Account::setValue(float value)
{
	if (value <= 0)
		throw(NegativeValueException());
	this->_value += value;
}

// std::ostream &operator<<(std::ostream &p_os, const Bank::Account p_account) {
//     p_os << "[" << p_account._id << "] - [" << p_account._value << "]";
// 	return (p_os);
// }

Bank::Bank(float liquidity): _clientAccounts(std::vector<Account>()) {
	if (liquidity <= 0)
		throw NegativeValueException();
	_liquidity = liquidity;
	std::cout << "Bank parameter(float) constructor called" << std::endl;
} 

Bank::~Bank() {
    std::cout << "Bank default destructor called" << std::endl;
}

// //Member Functions 
void Bank::transfer(int src, int dest, float ammount) {
	if (ammount <= 0) {
		throw NegativeValueException();
	}
	if ((*this)[src] < ammount)
	{
		throw NotEnoughBalanceException();
	}
	this->getAccount(src).setValue((*this)[src] - ammount);
	this->getAccount(dest).setValue(ammount * 0.96);
	this->setLiquidity(this->getLiquidity() + ammount * 0.04);
}


void Bank::createAccount(float initial_balance)
{
	this->setClient(initial_balance);
	std::cout << "Client "<< _clientAccounts.size() - 1 << " created(" << _clientAccounts.back().getValue() << "$)" << std::endl;
}

// Setters
void Bank::setLiquidity(float liquidity) {
    _liquidity = liquidity;
}

void Bank::setClient(float initial_balance)
{
	if (_clientAccounts.size() == 0)
		_clientAccounts.push_back(Bank::Account(0));
	else
		_clientAccounts.push_back(Bank::Account(_clientAccounts.back().getId() + 1));
	_clientAccounts.back().setValue(initial_balance);
}
// Getters

 float &Bank::getLiquidity() {
	return _liquidity;
}

const std::vector<Bank::Account> &Bank::getClients() {
	return _clientAccounts;
}

Bank::Account &Bank::getAccount(int id){
	try {
		if ( id < 0)
			throw NegativeValueException();
		return (_clientAccounts[id]);
	}
	catch (std::exception &e)
	{
		std::cout << "HERE";
		throw e.what();
	}
}

//Exceptions
const char *Bank::DuplicateIdException::what() const throw() {
	return "Account Id already exists";
}

const char *Bank::NegativeValueException::what() const throw() {
	return "Cannot accept Negative or Zero value";
}

const char *Bank::NotEnoughBalanceException::what() const throw() {
	return "Insuficient balance";
}

const char *Bank::AccountDoesNotExistException::what() const throw() {
	return "Account with that id doesn not exist";
}

// Friends
// std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
// 		p_os << "Bank informations : " << std::endl;
// 		p_os << "Liquidity : " << p_bank._liquidity << std::endl;
// 		for (std::vector<Bank::Account>::const_iterator it = p_bank._clientAccounts.begin(); it != p_bank._clientAccounts.end(); ++it)
// 			p_os << *it << std::endl;
// 		return (p_os);
// }
const float &Bank::operator[](int id) {
	try {
		if ( id < 0)
			throw NegativeValueException();
		return (_clientAccounts[id].getValue());
	}
	catch (std::exception &e)
	{
		std::cout << "HERE";
		throw e.what();
	}
	throw AccountDoesNotExistException();
}