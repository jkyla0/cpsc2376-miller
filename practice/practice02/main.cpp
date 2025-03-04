<<<<<<< HEAD
// practice02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>



void displayMenu()
{
    std::cout << "Welcome to Ace Banking " << std::endl;
    std::cout << "Main Menu: " << std::endl;
    std::cout << "1. Balance" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw " << std::endl;
    std::cout << "4. Exit" << std::endl;
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

void displayMenu()
{
    std::cout<<"Main Menu:"<<std::endl;
    std::cout<<"1. Check Balance"<<std::endl;
    std::cout<<"2. Deposit Money"<<std::endl;
    std::cout<<"3. Withdraw Money"<<std::endl;
    std::cout<<"4. Exit"<<std::endl;
>>>>>>> 063897d50dbe68c71d57e0bd01d9d8cd4bbb3ae8
}

void menuSelection(int choice, double& balance)
{
<<<<<<< HEAD
    switch (choice)
    {
    case 1:
        std::cout << "Current Balance: $" << std::fixed<< std::setprecision(2)<< balance << std::endl;
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
        accountBalance<<balance;
    }
    else
    {
        std::cerr << "not able to load file";
=======
    
    switch (choice)
    {
        case 1:
        std::cout<<"Current Balance: $"<<std::fixed<<std::setprecision(2)<<balance<<std::endl;
        break;

        case 2:
        double deposit;
        std::cout<<"Deposit amount: $";
        std::cin>> deposit;
        if (deposit > 0)
        {
            balance += deposit;
            std::cout<<"Deposited Amount $"<<std::fixed<<std::setprecision(2)<<deposit<<std::endl;
            std::cout<<"Check Balance for updated total!\n"<<std::endl;
        }
        else
        {
            std::cout<<"Please enter a positive amount."<<std::endl;
        }
        break;

        case 3:
        double withdraw;
        std::cout<<"Withdrawal amount: $";
        std::cin>> withdraw;
        if (withdraw > 0 && withdraw < balance)
        {
            balance -= withdraw;
            std::cout<<"The withdraw amount is $"<<std::fixed<<std::setprecision(2)<<withdraw<<std::endl;
        }
        else
        {
            std::cout<<"Enter valid withdrawl amount or check your balance."<<std::endl;
        }
        break;

        case 4:
        std::cout<<"You chose to exit .... Have a nice day!"<<std::endl;
        break;

        default:
        std::cout<<"Invalid choice. Select 1-4"<<std::endl;
 
    }
}

void updateBalanceToFile(double balance)
{
    std::ofstream moneyTotal("account_balance.txt");
   
    if(moneyTotal.is_open())
    {
        moneyTotal<<balance<<std::endl;
        moneyTotal.close();
    }
    else
    {
        std::cerr<<"Not able to load account"<<std::endl;
>>>>>>> 063897d50dbe68c71d57e0bd01d9d8cd4bbb3ae8
    }
}

int main()
{
<<<<<<< HEAD
    double balance = 0.0; //having problems with setting value to desired balance
    std::ifstream startingBalance{ "account_balance.txt"};

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


=======
    //open file

    std::ifstream moneyTotal("account_balance.txt");

    double balance = 175.39; 
   
    if(moneyTotal.is_open())
    {
        moneyTotal >> balance;
        moneyTotal.close();
    }
    else if (!moneyTotal.is_open())
    {
        balance = 100.00;
        updateBalanceToFile(balance);
    }
    
    std::cout<<"Welcome to Ace Banking"<<std::endl; 
    int choice;
    do
    {   
        displayMenu();

        std::cout<<"Enter Choice from Menu: ";
        std::cin>> choice;

        menuSelection(choice, balance);
        updateBalanceToFile(balance);
    
    } while(choice != 4);
    

    return 0;
}
>>>>>>> 063897d50dbe68c71d57e0bd01d9d8cd4bbb3ae8
