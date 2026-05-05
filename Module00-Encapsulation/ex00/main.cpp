#include <iostream>
#include <vector>
#include <exception>
#include "Account.hpp"
#include "Bank.hpp"

int main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	try {
		Account accountA = Account(0);
		
		//accountA.setValue(100);
	
		Account accountB = Account(1);
		
		//accountB.setValue(100);
	
		 Bank bank = Bank(999);
		// bank.liquidity = 999;
		// bank.clientAccounts.push_back(&accountA);
		bank.setClient(accountA);
		// bank.clientAccounts.push_back(&accountB);
		bank.setClient(accountB);
	
		// bank.liquidity -= 200;
		// accountA.value += 400;
	
		std::cout << "Account : " << std::endl;
		std::cout << accountA << std::endl;
		// std::cout << accountB << std::endl;
	
		std::cout << " ----- " << std::endl;
		std::cout << "Bank : " << std::endl;
		std::cout << bank << "HERE\n\n:" << std::endl;
		std::cout << bank[10] << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "Error: "  << e.what() << std::endl;
	}
	return (0);
}
