#include <iostream>
#include <vector>
#include <exception>
#include "Bank.hpp"

int getInput(const std::string &prompt) 
{
	
	long res;

	std::cout << prompt << std::endl;
	std::cin >> res;
	if (std::cin.eof())
		throw Bank::NegativeValueException();
	return (res);
}

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Error\nUsage: ./bank <Liquidity>" << std::endl;
		exit(1);
	}
	try {
		// bank.liquidity = 999;
		Bank bank = Bank(std::atol(av[1]));
		while (1)
		{
			try {
				switch (getInput("Welcome to the Bank:\n\n[1] - Add Account\n[2] - Exit"))
				{
					case 1:
						bank.setClient(getInput("\nClient Id:"));
						break;
					case 2:
						std::exit(0);
					case 3:
					float id = getInput("Which Account do you wish to see?\n:");
					std:: cout  << "ID Found: " << id << "\nBalance: " << bank[id] << std::endl;
				}
			std::cout << " ----- " << std::endl;
			std::cout << "Bank : " << std::endl;
			std::cout << "Liquidity"  <<bank.getLiquidity() << std::endl;
			//std::cout << bank << "HERE\n\n:" << std::endl;
			// std::cout << bank[10] << std::endl;
			}
			catch (std::exception &e){
				std::cerr << "Error: "  << e.what() << std::endl;
				if (e.what() == Bank::NegativeValueException().what()) {
					std::exit(1);
				}
			}
		}
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

return (0);
}

