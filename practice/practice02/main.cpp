// practice02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>



void displayMenu()
{
    std::cout << "Main Menu: " << std::endl;
    std::cout << "1. Balance" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw " << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void menuSelection(int choice, double& balance)
{
    switch (choice)
    {
    case 1:
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
        break;
    case 2:
        double deposit;
        std::cout << "Enter deposit amount: $";
        std::cin >> deposit;
        if (deposit > 0)
        {
            balance += deposit;
        }
        else
        {
            std::cout << "Enter positive amount";
        }
        break;
    case 3:
        double withdrawl;
        std::cout << "Enter withdrawl amount: $";
        std::cin >> withdrawl;

        if (withdrawl > 0 && withdrawl <= balance)
        {
            balance -= withdrawl;
        }
        else
        {
            std::cout << "Enter an amount within your balance";
        }
        break;
    case 4:
        std::cout << "Have a nice day!";
        break;
    default:
        std::cout << "Invalid input!";
    }
}

void updatedBalance(double balance)
{
    std::ofstream accountBalance{ "account_balance.txt" };
    if (accountBalance.is_open())
    {
        accountBalance << balance;
    }
    else
    {
        std::cerr << "not able to load file";
    }
}

int main()
{
    double balance = 0.0;
    std::ifstream startingBalance{ "account_balance.txt" };

    if (startingBalance.is_open())
    {
        balance = 175.39;
        startingBalance >> balance;
    }
    else
    {
        balance = 100.00;
        startingBalance >> balance;
    }

    int choice;
    std::cout << "Welcome to Ace Banking " << std::endl;

    do
    {
        displayMenu();

        std::cout << "Select from the menu: ";
        std::cin >> choice;

        if (choice < 1 || choice > 4)
        {
            std::cout << "invalid choice!";
        }
        else
        {
            menuSelection(choice, balance);
            updatedBalance(balance);
        }

    } while (choice != 4);

    return 0;
}

