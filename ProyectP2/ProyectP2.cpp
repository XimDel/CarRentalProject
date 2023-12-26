#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <climits>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>


using namespace std;

int menuOption, modifyOption, auxOption;
int rentalPeriod, price, cost, km, kmTotal, location, plateFound, aux;
string plate, newPlate, type, availability, printSpaces;
char confirmOption;
int coincidence, income, auxIncome, showLimit;

vector<vector<string>> content;
vector<string> row;
string line, word;

void carCatalogMenu();
void rentalMenu();
void incomeMenu();
void modifyCarMenu();
void addCarMenu();
void rentCarMenu();
void reenterCarMenu();

void showStock();
void showStockByType();
void showStockByAvailability();
void showStockHistory();
int availableCars();
int rentedCars();
void findLicensePlate();
void showCarInfo();
void deleteCar();
void sortSpaces(int category, int number);
void totalIncome();
void incomeByCars();

void fileCheck();
void rewriteFile();
void optionFail();
void writingCheck();

int main() {
    fileCheck();
    do
    {

        system("cls");

        cout << "CAR RENTAL" << endl << endl;

        cout << "1. Cars Catalog" << endl;
        cout << "2. Rent" << endl;
        cout << "3. Income" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Choose an option: ";
        cin >> menuOption;
        optionFail();
        system("cls");
        switch (menuOption)
        {
        case 1:
        {
            carCatalogMenu();
            menuOption = 0;
            break;
        }

        case 2:
        {
            rentalMenu();
            menuOption = 0;
            break;
        }

        case 3:
        {
            incomeMenu();
            menuOption = 0;
            break;
        }

        case 4:
        {
            cout << "Do you want to close the program?" << endl;
            cout << "Yes: Y" << endl;
            cout << "No: N" << endl;
            cin >> confirmOption;
            if (confirmOption == 'y' || confirmOption == 'Y')
            {
                rewriteFile();
                break;
            }
            else if(confirmOption == 'n' || confirmOption == 'N')
            {
                menuOption = 0;
                system("cls");
                break;
            }
            else if (confirmOption != 'n' || confirmOption != 'N')
            {
                menuOption = 0;
                cout << "This option is not available" << endl;
                system("pause");
                break;
            }
            break;
        }

        default:
        {
            cout << "This option is not available" << endl;
            system("pause");
            break;
        }
        }

    } while (menuOption != 4);

    return 0;
}

void carCatalogMenu()
{
    do
    {
        cout << "CARS CATALOG MENU\n" << endl;
        cout << "1. Stock \n";
        cout << "2. Find a car \n";
        cout << "3. Add a new car \n";
        cout << "4. Go back to the main menu \n" << endl;
        cout << "Choose an option: ";
        cout << " \n";
        cin >> menuOption;
        optionFail();
        system("cls");
        switch (menuOption)
        {
        case 1:
        {
            do
            {
                cout << "STOCK \n";
                cout << "Total Stock of cars: " << content[0].size() - 1 << " \n";
                cout << "Available cars: " << availableCars() << " \n";
                cout << "Rented cars: " << rentedCars() << " \n";
                cout << " \n";

                cout << "1. Full Stock of cars \n";
                cout << "2. Cars by Type \n";
                cout << "3. Cars by Availability \n";
                cout << "4. Go back to the Cars Catalog menu \n" << endl;
                cout << "Choose an option: ";
                cout << " \n";
                cin >> menuOption;
                optionFail();
                system("cls");
                switch (menuOption)
                {
                case 1: {
                    system("cls");
                    cout << "STOCK: \n";
                    showStock();
                    cout << "\n";
                    break; }
                case 2: {
                    cout << "TYPE OF CAR: \n";
                    cout << "1. Economic \n";
                    cout << "2. Intermediate \n";
                    cout << "3. Executive \n" << endl;
                    cout << "Choose an option: ";
                    cout << " \n";
                    cin >> menuOption;
                    optionFail();
                    system("cls");
                    switch (menuOption)
                    {
                    case 1:
                        cout << "Economic: \n";
                        type = "E",
                            showStockByType();
                        cout << "\n";
                        break;

                    case 2:
                        cout << "Intermediate: \n";
                        type = "I",
                            showStockByType();
                        cout << "\n";
                        break;

                    case 3:
                        cout << "Executive: \n";
                        type = "J",
                            showStockByType();
                        cout << "\n";
                        break;

                    default:
                        cout << "This option is not available" << endl;
                        break;
                    }
                    break; }
                case 3: {
                    cout << "AVAILABILITY \n";
                    cout << "1. Available cars \n";
                    cout << "2. Rented cars \n" << endl;
                    cout << "Choose an option: ";
                    cout << " \n";
                    cin >> menuOption;
                    optionFail();
                    system("cls");
                    switch (menuOption)
                    {
                    case 1:
                        cout << "Available Cars: " << availableCars() << " \n";
                        availability = "1";
                        showStockByAvailability();
                        cout << "\n";
                        break;

                    case 2:
                        cout << "Rented Cars: " << rentedCars() << " \n";
                        availability = "0";
                        showStockByAvailability();
                        cout << "\n";
                        break;

                    default:
                        cout << "This option is not available" << endl;
                        break;
                    }
                    break; }
                case 4:break;
                default: {
                    cout << "This option is not available" << endl;
                    break; }
                }

            } while (menuOption != 4);
            menuOption = 0;
            break;
        }
        case 2:
        {
            cout << "FIND A CAR: \n";
            cout << "Input the car's license plate:" << endl;
            cin >> plate;
            writingCheck();
            findLicensePlate();

            do
            {
                
                if (plateFound == 1)
                {
                    showCarInfo();
                    cout << "1. Modify the features of the car \n";
                    cout << "2. Delete the car \n";
                    cout << "3. Go to the Rent menu \n";
                    cout << "4. Go back to the Car Catalog menu \n" << endl;
                    cout << "Choose an option: ";
                    cout << " \n";
                    cin >> menuOption;
                    optionFail();
                    system("cls");
                    switch (menuOption)
                    {
                    case 1:
                    {
                        modifyCarMenu();
                        break;
                    }
                    case 2:
                    {
                        cout << "Do you want to delete de car?" << endl;
                        cout << "Yes: Y" << endl;
                        cout << "No: N" << endl;
                        cin >> confirmOption;
                        if (confirmOption == 'y' || confirmOption == 'Y')
                        {
                            deleteCar();
                            cout << " \n";
                            menuOption = 4;
                            cout << " Car has been successfully deleted" << endl;
                        }
                        else if (confirmOption == 'n' || confirmOption == 'N')
                        {
                            menuOption = 3;
                            system("cls");
                            break;
                        }
                        else if (confirmOption != 'n' || confirmOption != 'N')
                        {
                            cout << "This option is not available" << endl;
                            system("pause");
                            break;
                        }
                        break;
                    }
                    case 3:
                        rentalMenu();
                        break;
                    case 4:
                        break;
                    default: {
                        cout << "This option is not available" << endl;
                        break; }
                    }
                }
                else if (plateFound == 0)
                {
                    cout << "1. Search with a different License plate" << endl;
                    cout << "2. Go back to the Car Catalog menu" << endl;
                    cin >> menuOption;
                    optionFail();
                    system("cls");
                    switch (menuOption)
                    {
                    case 1:
                        break;
                    case 2:
                    {
                        menuOption = 4;
                        break;
                    }
                    default:
                    {
                        cout << "This option is not available" << endl;
                        break;
                    }

                    }
                }

            } while (menuOption != 4);
            menuOption = 3;
            break;
        }
        case 3:
        {
            cout << "ADD A NEW CAR: \n";
            addCarMenu();
            //print new car information
            system("cls");
            cout << "Car successfully added!" << endl;
            cout << " \n";
            break;

        default:
            cout << "This option is not available" << endl;
            break;
        }
        }
    } while (menuOption != 4);
}
void rentalMenu()
{
    do
    {
        cout << "RENT" << endl << endl;
        cout << "1. Rent a car" << endl;
        cout << "2. Return a car" << endl;
        cout << "3. Rent history" << endl;
        cout << "4. Go back to the main menu" << endl << endl;
        cout << "Choose an option: ";
        cin >> menuOption;
        optionFail();
        system("cls");
        switch (menuOption)
        {
        case 1:
        {
            do
            {
                cout << "RENT A CAR" << endl << endl;
                cout << "Input the car's license plate:" << endl;
                cin >> plate;
                writingCheck();
                findLicensePlate();
                if (plateFound == 1)
                {
                    showCarInfo();
                    cout << "1. Rent" << endl;
                    cout << "2. Go back to the rent menu" << endl;
                    cout << "Choose an option: ";
                    cin >> menuOption;
                    optionFail();
                    system("cls");
                    switch (menuOption)
                    {
                    case 1:
                        rentCarMenu();
                        menuOption = 2;
                        break;
                    case 2:
                        menuOption = 2;
                        break;
                    }
                }
                else if (plateFound == 0)
                {
                    cout << "1. Find another car" << endl;
                    cout << "2. Go back to rent menu" << endl;
                    cin >> menuOption;
                    optionFail();
                    switch (menuOption)
                    {
                    case 1:
                        break;
                    case 2:
                    {
                        menuOption = 2;
                        break;
                    }
                    default:
                    {
                        cout << "This option is not available" << endl;
                        break;
                    }

                    }
                }
            } while (menuOption != 2);
            menuOption = 0;
            break;
        }

        case 2:
        {
            do
            {
                cout << "RETURN A CAR" << endl << endl;
                cout << "Input the car's license plate:" << endl;
                cin >> plate;
                writingCheck();
                findLicensePlate();
                if (plateFound == 1)
                {
                    showCarInfo();
                    cout << "1. Return" << endl;
                    cout << "2. Go back to rent menu" << endl;
                    cout << "Choose an option: ";
                    cin >> menuOption;
                    optionFail();
                    system("cls");
                    switch (menuOption)
                    {
                    case 1:
                        reenterCarMenu();
                        menuOption = 2;
                        break;
                    case 2:
                        menuOption = 2;
                        break;
                    }
                }
                else if (plateFound == 0)
                {
                    cout << "1. Find another car" << endl;
                    cout << "2. Go back to Rent menu" << endl;
                    cin >> menuOption;
                    optionFail();
                    switch (menuOption)
                    {
                    case 1:
                        break;
                    case 2:
                    {
                        menuOption = 2;
                        break;
                    }
                    default:
                    {
                        cout << "This option is not available" << endl;
                        break;
                    }

                    }
                }

            } while (menuOption != 2);
            menuOption = 0;
            break;
        }

        case 3:
        {
            cout << "Rent History" << endl;
            showStockHistory();
            cout << endl;
            break;
        }

        case 4:
        {
            break;
        }

        default:
        {
            cout << "This option is not available" << endl;
            break;
        }
        }
    } while (menuOption != 4);
}
void incomeMenu()
{
    do
    {
        cout << "INCOME" << endl << endl;
        cout << "Total income is: $";
        totalIncome();
        cout << endl << endl;

        cout << "1. Check income by car" << endl;
        cout << "2. Go back to the main menu" << endl << endl;
        cout << "Choose an option: ";
        cin >> menuOption;
        optionFail();
        switch (menuOption)
        {
        case 1:
        {
            incomeByCars();
            cout << endl;
            break;
        }
        case 2:
        {
            break;
        }
        default:
        {
            cout << "This option is not available" << endl;
        }
        }
    } while (menuOption != 2);
}
void modifyCarMenu()
{
    do {
        cout << "Modify car information:" << endl << endl;
        cout << "1. Plate" << endl;
        cout << "2. Make" << endl;
        cout << "3. Model" << endl;
        cout << "4. Mileage" << endl;
        cout << "5. Rent Price" << endl;
        cout << "6. Insurance type" << endl;
        cout << "7. Type of car" << endl;
        cout << "0. Go back" << endl << endl;
        cout << "Choose an option:" << endl;
        cin >> modifyOption;
        optionFail();
        system("cls");
        switch (modifyOption)
        {
        case 1:
        {
            cout << "LICENSE'S PLATE" << endl << endl;
            cout << "Input a new license Plate:" << endl << endl;
            cin >> newPlate;
            writingCheck();
            for (int i = 0, j = 1; j < content[0].size(); j++)
            {
                if (newPlate == content[i][j])
                {
                    if (location == j)
                    {
                        cout << "The license plate you entered is already assigned to the current car" << endl;
                        coincidence = 1;
                        break;
                    }
                    else
                    {
                        cout << "The license plate you entered already exists in the system" << endl;
                        coincidence = 1;
                        break;
                    }
                }
                else
                {
                    coincidence = 0;
                }
            }
            if (coincidence == 0)
            {
                cout << content[0][location] << " -> " << newPlate << endl;
                content[0][location] = newPlate;
                cout << "License's plate has been succesfully modified" << endl;
                cout << content[0][location] << endl;
            }

            cout << " \n";
            break;
        }
        case 2:
        {
            cout << "MAKE" << endl << endl;
            cout << "Input the new Make:" << endl << endl;
            cin >> newPlate;
            writingCheck();
            for (int i = 1, j = 1; j < content[0].size(); j++)
            {
                if (newPlate == content[i][j])
                {
                    if (location == j)
                    {
                        cout << "The make you entered is already assigned to the current car." << endl;
                        coincidence = 1;
                        break;
                    }
                }
                else
                {
                    coincidence = 0;
                }
            }
            if (coincidence == 0)
            {
                cout << content[1][location] << " -> " << newPlate << endl;
                content[1][location] = newPlate;
                cout << "Make has been succesfully modified" << endl;
                cout << content[1][location] << endl;
            }

            cout << " \n";
            break;
        }
        case 3:
        {
            cout << "MODEL" << endl << endl;
            cout << "Input the new model:" << endl << endl;
            cin >> newPlate;
            writingCheck();
            for (int i = 2, j = 1; j < content[0].size(); j++)
            {
                if (newPlate == content[i][j])
                {
                    if (location == j)
                    {
                        cout << "The model you entered is already assigned to the current car." << endl;
                        coincidence = 1;
                        break;
                    }
                }
                else
                {
                    coincidence = 0;
                }
            }
            if (coincidence == 0)
            {
                cout << content[2][location] << " -> " << newPlate << endl;
                content[2][location] = newPlate;
                cout << "Model has been succesfully modified" << endl;
                cout << content[2][location] << endl;
            }

            cout << " \n";
            break;
        }
        case 4:
        {
            cout << "MILEAGE" << endl << endl;
            cout << "Input the new mileage:" << endl << endl;
            cin >> km;
            optionFail();
            newPlate = std::to_string(km);

            cout << content[5][location] << " -> " << newPlate << endl;
            content[5][location] = newPlate;
            cout << "Mileage has been succesfully modified" << endl;
            cout << content[5][location] << endl;
            cout << " \n";
            break;
        }
        case 5:
        {
            cout << "RENT PRICE" << endl << endl;
            cout << "Input the new rent price:" << endl << endl;
            cin >> price;
            optionFail();
            newPlate = std::to_string(price);

            cout << content[8][location] << " -> " << newPlate << endl;
            content[8][location] = newPlate;
            cout << "Rent Price has been succesfully modified" << endl;
            cout << content[8][location] << endl;
            cout << " \n";
            break;
        }
        case 6:
        {
            cout << "INSURANCE'S TYPE" << endl << endl;
            cout << "1. Full" << endl;
            cout << "2. SOAT" << endl;
            cout << "3. SOAT + Simple Crash" << endl;
            cout << "Choose the type of insurance: " << endl;
            cin >> auxOption;
            optionFail();
            switch (auxOption)
            {
            case 1:
            {
                cout << content[4][location] << " -> FULL" << endl;
                content[4][location] = "F";
                cout << "Insurance's type has been succesfully modified" << endl;
                cout << content[4][location] << endl;
                cout << " \n";
                break;
            }
            case 2:
            {
                cout << content[4][location] << " -> SOAT" << endl;
                content[4][location] = "S";
                cout << "Insurance's type has been succesfully modified" << endl;
                cout << content[4][location] << endl;
                cout << " \n";
                break;
            }
            case 3:
            {
                cout << content[4][location] << " -> SOAT + Simple Crash" << endl;
                content[4][location] = "SC";
                cout << "Insurance's type has been succesfully modified" << endl;
                cout << content[4][location] << endl;
                cout << " \n";
                break;
            }
            }
            break;
        }
        case 7:
        {
            cout << "TYPE OF CAR" << endl << endl;
            cout << "1. Economic" << endl;
            cout << "2. Intermediate" << endl;
            cout << "3. Executive" << endl;
            cout << "Choose the type of car: " << endl;
            cin >> auxOption;
            switch (auxOption)
            {
            case 1:
            {
                cout << content[3][location] << " -> Economic" << endl;
                content[3][location] = "E";
                cout << "Type of car has been succesfully modified" << endl;
                cout << content[3][location] << endl;
                cout << " \n";
                break;
            }
            case 2:
            {
                cout << content[3][location] << " -> Intermediate" << endl;
                content[3][location] = "I";
                cout << "Type of car has been succesfully modified" << endl;
                cout << content[3][location] << endl;
                cout << " \n";
                break;
            }
            case 3:
            {
                cout << content[3][location] << " -> EXECUTIVE" << endl;
                content[3][location] = "J";
                cout << "Type of car has been succesfully modified" << endl;
                cout << content[3][location] << endl;
                cout << " \n";
                break;
            }
            }
            break;
        }
        case 0:
        {
            menuOption = 3;
            break;
        }

        }
    } while (modifyOption != 0);
}
void addCarMenu()
{
    cout << "LICENSE'S PLATE" << endl << endl;
    do {
        cout << "Input the license's plate:" << endl << endl;
        cin >> newPlate;
        writingCheck();
        for (int i = 0, j = 1; j < content[0].size(); j++)
        {
            if (newPlate == content[i][j])
            {
                system("cls");
                cout << "The license plate you entered already exists in the system" << endl;
                coincidence = 1;
                break;
            }
            else
            {
                coincidence = 0;
            }
        }
        if (newPlate.length() < 6 || newPlate.length() > 6)
        {
            cout << "Input a valid license's plate" << endl;
        }
    } while (coincidence == 1 || newPlate.length() < 6 || newPlate.length() > 6);
    if (coincidence == 0)
    {
        content[0].push_back(newPlate);
    }
    cout << " \n";

    cout << "MAKE" << endl;
    cout << "Input the make:"  << endl;
    cin >> newPlate;
    writingCheck();
    content[1].push_back(newPlate);
    cout << " \n";

    cout << "MODEL" << endl;
    cin >> newPlate;
    writingCheck();
    content[2].push_back(newPlate);
    cout << " \n";

    cout << "MILEAGE"  << endl;
    cout << "Input the mileage:" << endl;
    cin >> km;
    optionFail();
    newPlate = std::to_string(km);
    content[5].push_back(newPlate);
    cout << " \n";

    cout << "RENT PRICE"  << endl;
    cout << "Input the rent price:"  << endl;
    cin >> price;
    optionFail();
    newPlate = std::to_string(price);
    content[8].push_back(newPlate);
    cout << " \n";

    cout << "INSURANCE'S TYPE"  << endl;
    cout << "1. Full" << endl;
    cout << "2. SOAT" << endl;
    cout << "3. SOAT + Simple Crash" << endl;
    cout << "Choose the insurance's type: " << endl;
    cin >> auxOption;
    optionFail();
    switch (auxOption)
    {
    case 1:
    {
        newPlate = "F";
        content[4].push_back(newPlate);
        cout << " \n";
        break;
    }
    case 2:
    {
        newPlate = "S";
        content[4].push_back(newPlate);
        cout << " \n";
        break;
    }
    case 3:
    {
        newPlate = "SC";
        content[4].push_back(newPlate);
        cout << " \n";
        break;
    }
    }

    cout << "TYPE OF CAR" << endl;
    cout << "1. Economic" << endl;
    cout << "2. intermediate" << endl;
    cout << "3. Executive" << endl;
    cout << "Choose the type of car: " << endl;
    cin >> auxOption;
    switch (auxOption)
    {
    case 1:
    {
        newPlate = "E";
        content[3].push_back(newPlate);
        cout << " \n";
        break;
    }
    case 2:
    {
        newPlate = "I";
        content[3].push_back(newPlate);
        cout << " \n";
        cout << " \n";
        break;
    }
    case 3:
    {
        newPlate = "J";
        content[3].push_back(newPlate);
        cout << " \n";
        break;
    }
    }
    cout << " \n";
    newPlate = "1";
    content[6].push_back(newPlate);//CurrentState
    newPlate = "0";
    content[7].push_back(newPlate);//Days
    newPlate = " ";
    content[9].push_back(newPlate);//Income
    newPlate = "0";
}
void rentCarMenu()
{
    if (content[6][location] == "1")
    {

        cout << "How long do you want to rent it: " << endl;
        cin >> rentalPeriod;
        optionFail();
        newPlate = std::to_string(rentalPeriod);
        content[7][location] = newPlate;

        std::string::size_type sz;
        price = stoi(content[8][location], &sz);
        cost = rentalPeriod * price;
        cout << "Total price to pay: $" << cost << endl;

        content[9][location] = std::to_string(cost);

        content[6][location] = "0";
        cout << "Car successfully rented" << endl;
    }
    else if (content[6][location] == "0")
    {
        cout << "This car is already rented" << endl;
    }
}
void reenterCarMenu()
{
    if (content[6][location] == "0")
    {
        cout << "Enter the number of kilometers traveled:" << endl;
        cin >> km;
        optionFail();

        std::string::size_type sz;
        kmTotal = stoi(content[5][location], &sz);
        kmTotal = kmTotal + km;
        cout << "The new kilometers total is: " << kmTotal << "km" << endl;

        content[5][location] = std::to_string(km);
        content[6][location] = "1";
        cout << "The car has been successfully returned" << endl;
    }
    else if (content[6][location] == "1")
    {
        cout << "This car is not currently rented" << endl;
    }
}



void showStock()
{
    showLimit = 5;
    for (int i = 0, j = 0; i < content.size() - 4; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
        }
        if (i == content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 0; j < content[0].size(); j++)
    {
        i = 0;
        for (; i < content.size() - 4; i++)
        {
            if (i == 0)
                cout << "[  ";
            if (i != content.size() - showLimit)
            {
                cout << content[i][j];
                sortSpaces(i, j);
            }
            if (i == content.size() - showLimit)
            {
                cout << content[i][j];
                sortSpaces(i, j);
            }
        }
    }
}
void showStockByType()
{
    showLimit = 5;
    for (int i = 0, j = 0; i < content.size() - 4; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
        }
        if (i == content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 3; j < content[0].size(); j++)
    {
        i = 3;
        if (content[i][j] == type)
        {
            i = 0;
            for (; i < content.size() - 4; i++)
            {
                if (i == 0)
                    cout << "[  ";
                if (i != content.size() - showLimit)
                {
                    cout << content[i][j];
                    sortSpaces(i, j);
                }
                if (i == content.size() - showLimit)
                {
                    cout << content[i][j];
                    sortSpaces(i, j);
                }
            }
        }
    }
}
void showStockByAvailability()
{
    showLimit = 5;
    for (int i = 0, j = 0; i < content.size() - 4; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
        }
        if (i == content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 6; j < content[0].size(); j++)
    {
        i = 6;
        if (content[i][j] == availability)
        {
            i = 0;
            for (; i < content.size() - 4; i++)
            {
                if (i == 0)
                    cout << "[  ";
                if (i != content.size() - showLimit)
                {
                    cout << content[i][j];
                    sortSpaces(i, j);
                }
                if (i == content.size() - showLimit)
                {
                    cout << content[i][j];
                    sortSpaces(i, j);
                }
            }
        }
    }
}
void showStockHistory()
{
    showLimit = 4;
    for (int i = 0, j = 0; i < content.size() - 3; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
        }
        if (i == content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 7; j < content[0].size(); j++)
    {
        i = 7;
        if (content[i][j] != "0")
        {
            i = 0;
            for (; i < content.size() - 3; i++)
            {
                if (i == 0)
                    cout << "[  ";
                if (i != content.size() - showLimit)
                {
                    cout << content[i][j];
                    sortSpaces(i, j);
                }
                if (i == content.size() - showLimit)
                {
                    cout << content[i][j];
                    sortSpaces(i, j);
                }
            }
        }
    }
}
int availableCars()
{
    int countAvailableCars = 0;
    for (int i = 6, j = 1; j < content[0].size(); j++) {
        if (content[i][j] == "1") {
            countAvailableCars++;
        }
    }
    return countAvailableCars;
}
int rentedCars()
{
    int countRentedCars = 0;
    for (int i = 6, j = 1; j < content[0].size(); j++) {
        if (content[i][j] == "0") {
            countRentedCars++;
        }
    }
    return countRentedCars;
}
void findLicensePlate()
{
    for (int i = 0, j = 0; j < content[0].size(); j++)
    {
        aux = 1;
        if (plate == content[i][j])
        {
            plateFound = 1;
            location = j;
            break;
        }
        else
        {
            aux = 0;
        }
    }
    if (aux == 0)
    {
        cout << "License's plate not found" << endl;
        plateFound = 0;
    }
}
void showCarInfo()
{
    showLimit = 2;
    for (int i = 0, j = 0; i < content.size() - 1; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
        }
        if (i == content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
            cout << endl;
        }
    }
    for (int j = location, i = 0; i < content.size() - 1; i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
        }
        if (i == content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
            cout << endl;
        }
    }
}
void deleteCar()
{
    for (int i = 0; i < content.size(); i++)//Replace the last car selected for the last one in the vector 
    {
        string auxiliar = content[i][content[0].size() - 1];
        content[i][location] = auxiliar;
    }

    for (int i = 0; i < content.size(); i++)//Deletes the last element of the vector
    {
        content[i].pop_back();
    }
}
void sortSpaces(int category, int number)
{
    printSpaces = content[category][number];
    int spaces = 12 - printSpaces.length();

    if (category != content.size() - showLimit)
    {
        for (int l = 0; l < spaces; l++)
        {
            cout << " ";
        }
        cout << "|";
    }
    else
    {
        for (int l = 0; l < spaces; l++)
        {
            cout << " ";
        }
        cout << "]\n";
    }
}


void totalIncome()
{
    for (int j = 1; j < content[0].size(); j++)
    {
        std::string::size_type sz;
        auxIncome = stoi(content[9][j], &sz);

        income = income + auxIncome;
        //std::cout << "content[9][" << j << "] = " << content[9][j] << std::endl; print whole income per car
    }
    cout << income;
    income = 0;
}

void incomeByCars()
{
    showLimit = 1;
    for (int i = 0, j = 0; i < content.size(); i++)
    {
        if (i == 0)
            cout << "[  ";
        if (i != content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
        }
        if (i == content.size() - showLimit)
        {
            cout << content[i][j];
            sortSpaces(i, j);
            cout << endl;
        }
    }
    for (int j = 1, i = 0; j < content[0].size(); j++)
    {
        i = 0;
        for (; i < content.size(); i++)
        {
            if (i == 0)
                cout << "[  ";
            if (i != content.size() - showLimit)
            {
                cout << content[i][j];
                sortSpaces(i, j);
            }
            if (i == content.size() - showLimit)
            {
                cout << content[i][j];
                sortSpaces(i, j);
            }
        }
    }
}

void fileCheck()
{
    fstream Database("Database.txt", ios::in);
    if (Database.is_open())
    {
        while (getline(Database, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
    {
        Database.open("Database.txt", ios::out);

        Database << "Plate,\n";
        Database << "Make,\n";
        Database << "Model,\n";
        Database << "Car Type,\n";
        Database << "Insurance,\n";
        Database << "Mileage,\n";
        Database << "Availability,\n";
        Database << "Days,\n";
        Database << "Price,\n";
        Database << "Income,\n";

        Database.close();
        fstream Database("Database.txt", ios::in);

        while (getline(Database, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }

    Database.close();
}
void rewriteFile()
{
    ofstream Database;

    Database.open("Database.txt", ios::out);

    for (int i = 0, j = 0; i < content.size(); i++)
    {
        for (; j < content[0].size(); j++)
        {
            if (j == content[0].size() - 1)
            {
                Database << content[i][j] << "," << endl;
                break;
            }
            else
            {
                Database << content[i][j] << ",";
            }
        }
        j = 0;
    }

    Database.close();
}
void optionFail()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Not a valid option" << endl;
        getchar();
    }
}
void writingCheck()
{
    for (int i = 0; i < plate.length(); i++)
    {
        plate[i] = toupper(plate[i]);
    }
    for (int i = 0; i < newPlate.length(); i++)
    {
        newPlate[i] = toupper(newPlate[i]);
    }
}
