// TLAP - CourseWork2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "InfoSystem.h"
using namespace std;

int choice = 0;         // admin or customer (1 - 2)
int decision;

int j = 0;              // index arrayCustomer

Customer* arrayCustomer[10];

float countPet = 0;
float countDog = 0;
float countCat = 0;
float countParrot = 0;

int initializingApp()
{
    system("cls");

    cout << "###### Welcome to the Virtual Pet Game ######" << endl << endl;
    do
    {
        cout << endl;
        cout << "Would you like to run the application as an Administrator or as a Customer? " << endl << endl;
        cout << "Press 1 to run it as an Administrator." << endl;
        cout << "Press 2 to run it as a Customer." << endl;
        cout << "Press 0 to quit the application." << endl;
        cin >> choice;
        system("cls");
        if (choice == 0)
        {
            choice = 3;
        }

    } while (choice == 0);

    return choice;
}

int adminLoop()
{
    system("cls");

    int choice2 = 0;

    cout << "You are running the application as an Administrator" << endl << endl;

    do
    {
        cout << endl << endl;
        cout << "What would you like to do?" << endl;
        cout << "Press 1 show customers." << endl;
        cout << "Press 2 show popularity." << endl;
        cout << "Press 3 to reset application." << endl;
        cin >> choice2;
    
        switch (choice2){

            case 1:         // show customers

                system("cls");

                cout << "Customers: " << endl;

                for (int k = 0; k < j; k++){

                    cout<< arrayCustomer[k] ->getCustomerName() <<endl;
                }

                break;

            case 2:         // pet popularity

                system("cls");

                cout<< "DOG: ";
                cout<< (countDog*100 / countPet ) << "%" << endl;

                cout<< "CAT: ";
                cout<< (countCat / countPet)*100 << "%" << endl;

                cout<< "PARROT: ";
                cout<< (countParrot / countPet )*100 << "%"<< endl;

                break;

            case 3:
                initializingApp();
                choice2 = 0;
        }

    } while (choice2 != 0);

    return 0;
}

int customerLoop()
{
    cout << "You are running the application as Customer" << endl << endl;

    Customer* customer1 = new Customer(); cout << endl;

    arrayCustomer[j] = customer1;

    cout<< "Prueba de array "<<endl;
    cout<< arrayCustomer[j] -> getCustomerAge() <<endl;

    j++;

    system("cls");
    cout << "Welcome " << customer1->getCustomerName() << endl;
    int choice2 = 0;
    do
    {
        cout << endl << endl;
        cout << "What would you like to do?" << endl;
        cout << "Press 1 to add funds." << endl;
        cout << "Press 2 to check your balance." << endl;
        cout << "Press 3 to check the number of pets you own." << endl;
        cout << "Press 4 to buy a new pet." << endl;
        cout << "Press 5 to check personal details." << endl;
        cout << "Press 6 to reset the application." << endl;
        cout << "Press 0 to quit the application." << endl;
        cin >> choice2;
        system("cls");

        // add funds
        if (choice2 == 1)
        {

            int addFounds;

            cout << "Please, how much would you like to add?";
            cin >> addFounds;
            customer1->addFunds(addFounds);
            system("cls");
            cout << "Thank you, your current balance is " << customer1->getCustomerBudget() << endl;

        }
        else if (choice2 == 2)      // check balance
        {
            system("cls");
            cout << "Your current balance is " << customer1->getCustomerBudget() << endl;
        }
        else if (choice2 == 3)      // number of pets
        {
            system("cls");
            cout << "You own " << customer1->getNumberOfPets() << " pets." << endl;
            cout << "Press 0 to continue " << endl;
            cin >> choice;
            system("cls");
        }
        else if (choice2 == 4)
        {
            int showPet = 0;

            system("cls");
            cout << endl;
            cout << "Which pet would you like to buy? " << endl;
            cout << "Press 1 to buy a dog" << endl;
            cout << "Press 2 to buy a cat" << endl;
            cout << "Press 3 to buy a parrot" << endl;
            cout << "Press 4 to go back" << endl;
            cin >> showPet;
            system("cls");

            if (showPet == 1)       // select dog
            {
                system("cls");
                Dog* dog = new Dog;
                dog->getPetDescription();

                cout << "The current price is  ";

                // DESCUENTO
                if (customer1->getCustomerAge() < 14)
                {
                    cout<< dog->getPrice() - dog->getPrice()*0.25 << endl;
                }
                else if (customer1->getCustomerAge() > 70)
                {
                    cout<< dog->getPrice() - dog->getPrice()*0.5 << endl;
                }
                else if (customer1->getCustomerAge() > 14 || customer1->getCustomerAge() < 70)
                {
                    cout<< dog->getPrice()<< endl;
                }

                cout << "Would you like to buy this pet?" << endl << endl;
                cout << "1) Yes             2) No " << endl;
                cin >> decision;

                system("cls");
                if (decision == 1) {
                    if (customer1 -> getCustomerBudget() > dog -> getPrice() ){
                        countPet++;
                        countDog++;
                    }
                    customer1->buyPet(dog);
                    customer1->addFunds(customer1->getDiscount(dog));
                }

            }
            else if (showPet == 2)      // select cat
            {
                system("cls");
                Cat* cat = new Cat;
                cat->getPetDescription();

                cout << "The current price is  ";

                // Discount
                if (customer1->getCustomerAge() < 14)
                {
                    cout<< cat->getPrice() - cat->getPrice()*0.25 << endl;
                }
                else if (customer1->getCustomerAge() > 70)
                {
                    cout<< cat->getPrice() - cat->getPrice()*0.5 << endl;
                }
                else if (customer1->getCustomerAge() > 14 || customer1->getCustomerAge() < 70)
                {
                    cout<< cat->getPrice()<< endl;
                }

                cout << "Would you like to buy this pet?" << endl << endl;
                cout << "1) Yes             2) No " << endl;
                cin >> decision;

                system("cls");
                if (decision == 1) {
                    if (customer1 -> getCustomerBudget() > cat -> getPrice() ){
                        countPet++;
                        countCat++;
                    }
                    customer1->buyPet(cat);
                    customer1->addFunds(customer1->getDiscount(cat));
                }
            }
            else if (showPet == 3)      // select parrot
            {
                system("cls");
                Parrot* parrot = new Parrot;
                parrot->getPetDescription();

                cout << "The current price is  ";

                // DESCUENTO
                if (customer1->getCustomerAge() < 14)
                {
                    cout<< parrot->getPrice() - parrot->getPrice()*0.25 << endl;
                }
                else if (customer1->getCustomerAge() > 70)
                {
                    cout<< parrot->getPrice() - parrot->getPrice()*0.5 << endl;
                }
                else if (customer1->getCustomerAge() > 14 || customer1->getCustomerAge() < 70)
                {
                    cout<< parrot->getPrice()<< endl;
                }

                cout << "Would you like to buy this pet?" << endl << endl;
                cout << "1) Yes             2) No " << endl;
                cin >> decision;

                system("cls");
                if (decision == 1) {
                    if (customer1 -> getCustomerBudget() > parrot -> getPrice() ){
                        countPet++;
                        countParrot++;
                    }
                customer1->buyPet(parrot);
                customer1->addFunds(customer1->getDiscount(parrot));}
            }
        }
        else if (choice2 == 5)
        {
            system("cls");
            cout << "###### PERSONAL DETAILS ######" << endl << endl;
            cout << "Name: " << customer1->getCustomerName() << endl;
            cout << "Age: " << customer1->getCustomerAge() << endl;
            cout << "Address: " << customer1->getCustomerAddress() << endl;
            cout << "Phone number: " << customer1->getCustomerPhoneNumber() << endl;
        }
        else if (choice2 == 6)
        {
            initializingApp();
            choice2 = 0;
        }

    } while (choice2 != 0);

    return 0;

}

int main()
{

    initializingApp();
    system("cls");

    while(1){
        switch(choice){
            case 1:
                adminLoop();
                break;
            case 2:
                customerLoop();
                break;
        }

    }

}
