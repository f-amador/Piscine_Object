#include "Bank.hpp"
// Constructors
Bank::Bank(): _liquidity(0), _clientAccounts(std::vector<Account>()) {
    std::cout << "Bank default constructor called" << std::endl;
}

Bank::Bank(unsigned int liquidity): _liquidity(liquidity), _clientAccounts(std::vector<Account>()) {
	std::cout << "Bank parameter(unsigned int) constructor called" << std::endl;
} 

Bank::~Bank() {
    std::cout << "Bank default destructor called" << std::endl;
}

// Setters
void Bank::setLiquidity(unsigned int liquidity) {
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

//Exceptions
const char *Bank::DuplicateIdException::what() const throw() {
	return "Account Id already exists";
}

// Friends
std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank._liquidity << std::endl;
		for (std::vector<Account>::const_iterator it = p_bank._clientAccounts.begin(); it != p_bank._clientAccounts.end(); ++it)
			p_os << *it << std::endl;
		return (p_os);
}