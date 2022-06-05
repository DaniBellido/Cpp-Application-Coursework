#pragma once
#include <string>

using namespace std;


//Parent Pet Class

class Pet
{
	protected: //attributes
        string petType;             // not change
        string petName;             // not change
        string petDescription;      // not change
        int petMood;
        int petEnergy;
        int petHunger;
        double petFriendliness;
        double petPrice;

        int popularity;


	public: //methods

    // int countPet;

	Pet()  // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< constructor 1
	{
		petMood = 70;
		petEnergy = 90;
		petHunger = 60;

		petFriendliness = (petMood + petEnergy + petHunger) / 3;

	}

	~Pet() {} //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Destructor

	//setters
	void setMood(int petMood_p) { petMood = petMood_p; }
	void setEnergy(int petEnergy_p) { petEnergy = petEnergy_p; }
	void setHunger(int petHunger_p) { petHunger = petHunger_p; }
	void setPrice(double petPrice_p) { petPrice = petPrice_p; }
	void setPetName(string petName_p) { petName = petName_p; }
	void setPetType(string petType_p) { petType = petType_p; }
    void setPetPopularity(int petPopularity_p) { popularity = petPopularity_p; }

    // getters
	int getMood() { return petMood; }
	int getEnergy() { return petEnergy; }
	int getHunger() { return petHunger; }
    int getPopularity() { return popularity; }
	double getPrice() { return petPrice; }
	string getPetName() { return petName; }
	string getPetType() { return petType; }
	string getPetDescription() { return petDescription; }


};

// DOG DEFINITION

class Dog : public Pet
{
protected:

	string dogDescription()
	{
		cout << "DESCRIPTION: " << endl << endl;
		cout << "Dogs are mammals and quadrupeds." << endl;
		cout << "They are very affectionate animals and they like to play, especially with a ball or a stick." << endl;
		cout << "They are very territorial and can help with surveillance tasks." << endl;
		cout << "Their smell and hearing are much more developed than that of humans," << endl; cout << "but they do not perceive colors well because they are color blind." << endl;
		cout << "They are considered man's best friends." << endl << endl;

		cout << "                                 ,:'/   _..._" << endl;
		cout << "                                // ( `""-.._.'" << endl;
		cout << "                                \| /    6\___" << endl;
		cout << "                               |     6      4" << endl;
		cout << "                               |            /" << endl;
		cout << "                               \_       .--'" << endl;
		cout << "                                (_'---'`)" << endl;
		cout << "                                / `'---`()" << endl;
		cout << "                              ,'        |" << endl;
		cout << "              ,            .'`          |" << endl;
		cout << "              )\       _.-'             ;" << endl;
		cout << "             / |    .'`   _            /" << endl;
		cout << "           /` /   .'       '.        , |" << endl;
		cout << "          /  /   /           \   ;   | |" << endl;
		cout << "          |  \  |            |  .|   | |" << endl;
		cout << "           \  ` |           /.-' |   | |" << endl;
		cout << "            '-..-\       _.;.._  |   |.;-." << endl;
		cout << "                  \    <`.._  )) |  .;-. ))" << endl;
		cout << "                  (__.  `  ))-'  \_    ))'" << endl;
		cout << "                      `'--'`      `'''`'" << endl;


		return petDescription;
	}

public:
	Dog() :Pet() //Constructor
	{
		petType = "dog";
		petDescription = dogDescription();
		petPrice = 120;

	}

	~Dog() {} //Destructor


};

class Cat : public Pet
{
private:

	string catDescription()
	{
		cout << "DESCRIPTION: " << endl << endl;
		cout << "Cats are mammals and quadrupeds." << endl;
		cout << "They are not very affectionate animals and they like to hunt smaller animals such as insects or mice." << endl;
		cout << "Among the felines, cats are the smallest." << endl; cout << "They are not dangerous but they can attack and hurt with their claws." << endl;
		cout << "Cats have been domesticated for nearly 10,000 years." << endl << endl;

		cout << " ,_     _" << endl;
		cout << " |\\_,-~ / " << endl;
		cout << " / _  _ |    ,--." << endl;
		cout << "(  @  @ )   / ,-'" << endl;
		cout << " \  _T_/-._( (" << endl;
		cout << " /         `. \ " << endl;
		cout << "|         _  \ |" << endl;
		cout << " \ \ ,  /      |" << endl;
		cout << "  || |-_\__   /" << endl;
		cout << " ((_/`(____,-'" << endl;

		return petDescription;
	}

public:
	Cat() :Pet() //Constructor
	{
		petType = "cat";
		petDescription = catDescription();
		petPrice = 100;
	}

	~Cat() {} //Destructor

};

class Parrot : public Pet
{
private:

	string parrotDescription()
	{
		cout << "DESCRIPTION: " << endl << endl;
		cout << "Parrots are intelligent birds." << endl;
		cout << "They have relatively large brains, they can learn and use simple tools." << endl;
		cout << "Some species have the ability to make sounds like human voices and have plumages with bright colors." << endl;
		cout << "The greatest diversity of parrots is found in South America and Australasia." << endl;


		cout << "              __.------." << endl;
		cout << "           .-' .---.    \ " << endl;
		cout << "         .'  .' O   )/'\ / " << endl;
		cout << "       .'    )     >:'  L" << endl;
		cout << "   .''/      (    _J:   |" << endl;
		cout << "  /  ''      \   / `\   F" << endl;
		cout << " J  '         L_(   _> J" << endl;
		cout << " |  ( (         `--' |/" << endl;
		cout << "J /  : :.      :  J" << endl;
		cout << "| |   :. :. :. : .:L" << endl;
		cout << "| \   .     .  .:'|F" << endl;
		cout << "| |       `:. .: ||" << endl;
		cout << "F ||         '  |||" << endl;
		cout << "| :)       : .  JJ" << endl;
		cout << "|) |            /F" << endl;
		cout << " V A           /J" << endl;
		cout << " || \_.-.   .-.FF" << endl;
		cout << "---'--. /<--\\ L----." << endl;
		cout << "      |||L   \||     |" << endl;
		cout << "      JJ))   `||     |" << endl;
		cout << "      )|___.---\----'" << endl;
		cout << ".--'""<'|/ |F" << endl;
		cout << "    |J`-'  FF" << endl;
		cout << "    | L : JJ" << endl;
		cout << "    | J  :||" << endl;
		cout << "    J | | ||" << endl;
		cout << "    J |_/\_F" << endl;
		cout << "    J |  |J" << endl;
		cout << "     L L ||" << endl;
		cout << "     | | |F" << endl;
		cout << "     | | |F" << endl;

		return petDescription;
	}

public:
	Parrot() :Pet() //Constructor
	{
		petType = "parrot";
		petDescription = parrotDescription();
		petPrice = 350;
	}

	~Parrot() {} //Destructor

};
