#include <iostream>
#include <vector>
#include <exception>
#include "Account.hpp"
#include "Bank.hpp"

int main()
{
	try {
		Account accountA = Account();
		// accountA.id = 0;
		// accountA.value = 100;
	
		// Account accountB = Account();
		// accountB.id = 1;
		// accountB.value = 100;
	
		 Bank bank = Bank();
		// bank.liquidity = 999;
		// bank.clientAccounts.push_back(&accountA);
		// bank.clientAccounts.push_back(&accountB);
	
		// bank.liquidity -= 200;
		// accountA.value += 400;
	
		std::cout << "Account : " << std::endl;
		std::cout << accountA << std::endl;
		// std::cout << accountB << std::endl;
	
		std::cout << " ----- " << std::endl;
	
		std::cout << "Bank : " << std::endl;
		std::cout << bank << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
