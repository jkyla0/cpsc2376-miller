#include <iostream>
#include <vector>

void displayMenu()
{
    std::cout << "1. Drink \n";
    std::cout << "2. Teddy Bear \n";
    std::cout << "3. Mystery Box \n";
    std::cout << "4. Roblux \n";
    std::cout << "0. Exit\n";


}

void selection(int choice)
{
    switch (choice)
    {
    case 1:
        std::cout << "Drink\n";
        break;
    case 2:
        std::cout << "Teddy Bear\n";
        break;
    case 3:
        std::cout << "Mystery Box\n";
        break;
    case 4:
        std::cout << "Roblux\n";
        break;
    default:
        std::cout << "Invalid choice!\n";
    }
}

void total(const std::vector<int>& finalList)
{
    std::cout << "\nYou grabbed item(s): \n";
    for (int item : finalList)
    {
        selection(item);
    }
    std::cout << "\n Good day to you!";
}

int main()
{
    std::vector<int> finalList;
    int choice;
    std::cout << "Welcome Traveler to the infamous Stop Shop \n\n";

    do
    {
        displayMenu();
        std::cout << "Grab your item(s): ";
        std::cin >> choice;

        if (choice == 0)
        {
            break;
        }
        if (choice < 1 || choice > 4)
        {
            std::cout << "Invalid input choice, please choose between 1-4";
            continue;
        }

        finalList.push_back(choice);
        selection(choice);
    } while (true);

    total(finalList);


    return 0;
}

