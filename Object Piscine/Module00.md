
# [[Encapsulation]]
## Overview

In this module, you will be introduce to a concept really important in object oriented programming. Let’s stop for 5 seconds to define a number of names that will serve you in this pool. 

1.  Object : a concept embodying a "thing".

2.  Instance of an object : A concrete entity corresponding to a given object. 

3.  Attributes : An internal variable of the instance of an object

4.  Method : a way to communicate with an instance of an object, to make it perform actions. 

Now that we agree on these 4 words ... Behold ... You guessed it !... The "Encapsulation" ! Behind this barbaric name hides in reality a rather simple concept: There are things that "belong" to an object, and these things may or may not be accessible by others. In Object Oriented Programming (OOP), we can define attributes and methods in two ways: 

	• Private : these attributes/methods will be usable only and strictly only by the object itself 
	• Public : these attributes/methods can be used/modified by the outside of the class

The idea is to make the object a bit like a black box : the exterior can only access what is public, and nothing of what happens in the black box, which would be private.

# Exercise 00 : Divide and conquer

*In this exercise we will receive a poorly constructed Bank and Account class(everything is public!). The main objective is to implement this Bank in a Object Oriented manner, through proper use of encapsulation, getters and setters and architecture*

```c++
#include <iostream>
#include <vector>

struct Account {
	int id;
	int value;

	Account(): id(-1), value(0) {}

	friend std::ostream& operator << (std::ostream& p_os, const Account& p_account) {
		p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
		return (p_os);
	}
};

struct Bank
{
	int liquidity;
	std::vector<Account *> clientAccounts;

	Bank(): liquidity(0) {}

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank) {
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (auto &clientAccount : p_bank.clientAccounts)
        p_os << *clientAccount << std::endl;
		return (p_os);
	}
};

int main()
{
	Account accountA = Account();
	accountA.id = 0;
	accountA.value = 100;
	Account accountB = Account();
	accountB.id = 1;
	accountB.value = 100;
	Bank bank = Bank();
	bank.liquidity = 999;
	bank.clientAccounts.push_back(&accountA);
	bank.clientAccounts.push_back(&accountB);
	bank.liquidity -= 200;
	accountA.value += 400;

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;
	std::cout << " ----- " << std::endl;
	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;
	return (0);
}

```

## Bank Class
### Private Attributes
1. `liquidity : float`
2. `clientAccounts : std::vector<Account>`
3. `Account` (nested class definition)
### Public Methods
#### Constructors/Destructors
1. `Bank(float Liquidity)` : Parameterized constructor (receives float to initialize liquidity, throws exception if value is negative or zero)
2. `~Bank()` : Destructor (cleans up dynamically allocated Account objects)
#### Getters
1. `float &getLiquidity() const` : Returns current bank liquidity
2. `const std::vector<Account*>& getClientAccounts() const` : Returns reference to client accounts vector
3. `Account* getAccount(int id) const` : Returns pointer to account with given ID (or nullptr if not found)
#### Setters
1. `void setLiquidity(float newLiquidity)` : Updates liquidity (validates non-negative)
2. `void addAccount(Account* account)` : Adds account to bank (with validation)
3. `void removeAccount(int accountId)` : Removes account by ID