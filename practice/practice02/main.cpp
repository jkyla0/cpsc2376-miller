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
}

void menuSelection(int choice, double& balance)
{
    
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
    }
}

int main()
{
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
