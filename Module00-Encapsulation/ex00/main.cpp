#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <limits>
#include "Bank.hpp"

int getInput(const std::string &prompt) 
{
	
	long res;

	std::cout << prompt << std::endl;
	std::cin >> res;
	if (std::cin.eof())
		throw Bank::NegativeValueException();
	std::cin.clear();
	return (res);
}

void toggle(const std::string &prompt)
{
	std::string tmp;
	std::cout << prompt << std::endl; 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, tmp);
}
float getInputf(const std::string &prompt) 
{
	
	float res;
	
	std::cout << prompt << std::endl;
	std::cin >> res;
	if (std::cin.eof())
		throw Bank::NegativeValueException();
	return (res);
}
int main(int ac, char *av[])
{
	std::srand(std::time(0));
	if (ac != 2)
	{
		std::cerr << "Error\nUsage: ./bank <Liquidity>" << std::endl;
		exit(1);
	}
	bool brk = true;
	//std::system("clear");
	try {
		// bank.liquidity = 999;
		Bank bank = Bank(std::atof(av[1]));
		std::cout << "INITIAL VALUE:" << std::atof(av[1]) << std::endl; 
		while (brk)
		{
			std::cout << " ----- " << std::endl;
			std::cout << "Bank : " << std::endl;
			std::cout << "Liquidity :"  << bank.getLiquidity() << std::endl;
			float id;
			try {
				switch (getInput("Welcome to the Bank:\n\n[1] - Add Account\n[2] - Check Balance\n[3] - Transfer\n[4] - Delete Account\n[5] - Exit"))
				{
					case 1:
						bank.createAccount(getInputf("\nInitial deposit?\n"));
						break ;
					case 2:
						id = getInput("Which Account do you wish to see?: \n");
						std:: cout  << "ID Found: " << id << "\nBalance: " << bank[id] << std::endl;
						break ;
					case 3:
						bank.transfer(getInput("\nSource Account: "), getInput("\nDestiny Account: "), getInputf("\nValue"));
						break ;
					case 4:
						bank.deleteAccount(getInput("\nAccound id: "));
						break ;
					case 5:
						brk = false;
						break ;
					default :
						std::cout << "No action provided" << std::endl;
				}
			toggle("\nPress any key to continue...");
			}
			catch (std::exception &e){
				std::cerr << "Error: "  << e.what() << std::endl;
			}
		}
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
return (0);
}

