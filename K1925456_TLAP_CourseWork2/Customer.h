#pragma once
#include<string>
#include "Pet.h"

using namespace std;
int i;
//Parent Customer Class
class Customer
{
    protected: //attributes
        string customerName;
        int customerAge;
        string customerAddress;
        string customerPhoneNumber;
        double customerBudget;
        int numberOfPets;
        Pet* newPet[20];


    public: //methods

        //Different constructors == Polymorphism
        Customer()  // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< constructor 1
        {
            cout << "Please enter a new customer name: " << endl;
            setCustomerName();
            cout << "Please enter the customer's age: " << endl;
            setCustomerAge();
            cout << "Please enter the customer's address: " << endl;
            setCustomerAddress();
            cout << "Please enter the customer's phone number: " << endl;
            setCustomerPhoneNumber();

            for ( i = 0; i < 5; i++)
            {
                newPet[i] = NULL;
            }
            // start with no pets

            numberOfPets = 0;
            customerBudget = 0;
            cout << "The initial budget for the customer is: " << customerBudget << endl;

        }

	Customer(double customerBudget) // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< constructor 2
	{
		cout << "Please enter a new customer name: " << endl;
		setCustomerName();
		cout << "Please enter the customer's age: " << endl;
		setCustomerAge();
		cout << "Please enter the customer's address: " << endl;
		setCustomerAddress();
		cout << "Please enter the customer's phone number: " << endl;
		setCustomerPhoneNumber();

		customerBudget = customerBudget;
		cout << "The initial budget for the customer is: " << customerBudget << endl;

	}

	//destructor
	~Customer() {}

	//setters

	void setCustomerName() { cin >> customerName; }
	void setCustomerAge() { cin >> customerAge; }
	void setCustomerAddress() { cin >> customerAddress; }
	void setCustomerPhoneNumber() { cin >> customerPhoneNumber; }


	//getters
	string getCustomerName() { return customerName; }
	string getCustomerAddress() { return customerAddress; }
	string getCustomerPhoneNumber() { return customerPhoneNumber; }
	double getCustomerBudget() { return customerBudget; }
	int getNumberOfPets() {return numberOfPets; }
	int getCustomerAge() { return customerAge; }
	double getDiscount(Pet* new_pet) { double newPrice = new_pet->getPrice() * 0 / 100; return newPrice; } //Discount of 0% for normal customers.

	//other operations
	int buyPet(Pet* new_pet)
	{
		if (customerBudget >= new_pet->getPrice())
		{
			customerBudget = customerBudget - new_pet->getPrice(); numberOfPets++;

			for (int i = 0; i < 5 && newPet[i] == NULL; i++) {

				// if an empty slot was found, add the bus and return 1 //(true)
				if (i < 5) {
					newPet[i] = new_pet;
					return 1;
				}
				// otherwise return 0 (false)
				else
				{
					return 0;
				}
			}

			cout << "CONGRATULATIONS! We hope you enjoy your new pet. " << endl;
		}
		else { system("cls"); cout << "SORRY! You do not have funds enough to buy this pet. " << endl; cout << "Please, ADD FUNDS to your wallet before purchasing" << endl; }

	}
	void addFunds(double customerBudget_p) { customerBudget = customerBudget + customerBudget_p; }
	void feedPet(Pet* new_pet) { new_pet->getHunger() + 25; new_pet->getEnergy() + 15; }
	void pettingPet(Pet* new_pet) { new_pet->getMood() + 20; new_pet->getEnergy() + 10;}

};

//class YoungCustomer : public Customer
//{
//	private: //attributes
//
//	public:
//
//		YoungCustomer() :Customer() //<<<<<<< Constructor 1
//		{
//
//		}
//
//		YoungCustomer(int customerBudget):Customer(customerBudget) //<<<<<<< Constructor 2
//		{
//
//		}
//		//destructor
//		~YoungCustomer() {}
//
//		double getDiscount(Pet* new_pet) { double newPrice = new_pet->getPrice() * 25 / 100; return newPrice; } //Discount of 25% for young customers
//
//};
//
//class PensionCustomer : public Customer
//{
//private: //attributes
//
//public:
//
//	PensionCustomer() :Customer() //<<<<<<< Constructor 1
//	{
//
//	}
//
//	PensionCustomer(int customerBudget) :Customer(customerBudget) //<<<<<<< Constructor 2
//	{
//
//	}
//	//destructor
//	~PensionCustomer() {}
//
//	double getDiscount(Pet* new_pet) { double newPrice = new_pet->getPrice() * 50 / 100; return newPrice; } //Discount of 50% for pensioners
//
//};
