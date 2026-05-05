#include "Bank.hpp"
// Constructors
Bank::Bank(): _liquidity(0), _clientAccounts(std::vector<Account>()) {
    std::cout << "Bank default constructor called" << std::endl;
}

Bank::Bank(float liquidity): _liquidity(liquidity), _clientAccounts(std::vector<Account>()) {
	std::cout << "Bank parameter(float) constructor called" << std::endl;
} 

Bank::~Bank() {
    std::cout << "Bank default destructor called" << std::endl;
}

//Member Functions 
void Bank::transfer(const Account &src, const Account &dest, float ammount) {
	(void)dest;
	(void)src;
	if (ammount <= 0) {
		throw NegativeValue();
	}
	if (src.getValue() < ammount)
	{

	}
}


// Setters
void Bank::setLiquidity(float liquidity) {
    _liquidity = liquidity;
}

void Bank::setClient(const Account & client)
{
	for (std::vector<Account>::const_iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it ++)
	{
		if (client.getId() == (*it).getId())
		{
			throw DuplicateIdException();
		}
	}
	_clientAccounts.push_back(client);
}
// Getters

const float &Bank::getLiquidity() {
	return _liquidity;
}

const std::vector<Account> &Bank::getClients() {
	return _clientAccounts;
}

//Exceptions
const char *Bank::DuplicateIdException::what() const throw() {
	return "Account Id already exists";
}

const char *Bank::NegativeValue::what() const throw() {
	return "Cannot accept Negative value";
}

// Friends
std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank._liquidity << std::endl;
		for (std::vector<Account>::const_iterator it = p_bank._clientAccounts.begin(); it != p_bank._clientAccounts.end(); ++it)
			p_os << *it << std::endl;
		return (p_os);
}
const Account &Bank::operator[](float id) {
	try {		
		Account *a = &_clientAccounts[id];
		throw (*a);
	}
	catch (std::exception &e)
	{
		std::cout << "HERE";
		throw e.what();
	}
}