#include "Bank.hpp"


Bank::Account::Account():_value(0) {
    //std::cout << "Account default constructor called" << std::endl;
}

Bank::Account::Account(float value): _value(value) {
    //std::cout << "Account parameter(float) constructor called" << std::endl;
}

Bank::Account::~Account(){
    //std::cout << "Account destructor called" << std::endl;
}

const float &Bank::Account::getValue(void) const {
    return (_value);
}

void Bank::Account::setValue(float value)
{
	this->_value += value;
}

Bank::Bank(float liquidity): _clientAccounts(std::map<int, Account>()) {
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
	if (_clientAccounts.find(src) == _clientAccounts.end() || _clientAccounts.find(dest) == _clientAccounts.end()) {
		throw AccountDoesNotExistException();
	}
	if (_clientAccounts[src].getValue() < ammount + ammount * 0.05)
	{
		throw NotEnoughBalanceException();
	}
	_clientAccounts[src].setValue(-ammount - (ammount * 0.05));
	_clientAccounts [dest].setValue(ammount);
	this->setLiquidity(this->getLiquidity() + ammount * 0.05);
}

void Bank::deleteAccount(int id) {
	if (id < 0)
		throw NegativeValueException();
	if (_clientAccounts.find(id) == _clientAccounts.end())
		throw AccountDoesNotExistException();
	_clientAccounts.erase(id);
	std::cout << "Account " << id << " deleted..." << std::endl;
}

void Bank::createAccount(float initial_balance)
{
	this->setClient(initial_balance);
}

// Setters
void Bank::setLiquidity(float liquidity) {
    _liquidity = liquidity;
}

void Bank::setClient(float initial_balance)
{

	while (true)
	{
		if (_clientAccounts.size() == 10000)
			throw BankIsFull();
		int tmp = rand() % 10000;
		if (_clientAccounts.find(tmp) == _clientAccounts.end()) {
			_clientAccounts.insert(std::pair<int, Bank::Account>(tmp, initial_balance));
			std::cout << "Client "<< tmp  << " created(" << _clientAccounts[tmp].getValue() << "$)" << std::endl;
			break ;
		}
	}
}
// Getters

 float &Bank::getLiquidity() {
	return _liquidity;
}

const std::map<int ,Bank::Account> &Bank::getClients() {
	return _clientAccounts;
}

//Exceptions
const char *Bank::NegativeValueException::what() const throw() {
	return "Cannot accept Negative or Zero value";
}

const char *Bank::NotEnoughBalanceException::what() const throw() {
	return "Insuficient balance";
}

const char *Bank::AccountDoesNotExistException::what() const throw() {
	return "Account with that id doesn not exist";
}

const char *Bank::NoAccountsInBank::what() const throw() {
	return "Bank doesn't have any accounts";
}

const char *Bank::BankIsFull::what() const throw() {
	return "Bank can't create anymore accounts";
}


const float &Bank::operator[](int id) {

	if ( id < 0)
		throw NegativeValueException();
	if (_clientAccounts.find(id) == _clientAccounts.end())
		throw AccountDoesNotExistException();
	return (_clientAccounts[id].getValue());
}