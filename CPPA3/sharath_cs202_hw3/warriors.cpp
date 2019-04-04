//Sharath Menon CS202 Programming Assignment 3
//this page manages the warriors class
#include "character.h"
using namespace std;

//default constructor for the warriors class
warriors::warriors()
{
	strength = 0;
	weapon = NULL;
}

//extended constructor for the warriors class
warriors::warriors(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio, int endurance, char* to_weapon):character(type_soldier, to_name, to_gender, years, mass, bio)
{
	strength = endurance;
	weapon = new char[strlen(to_weapon)+1];
	strcpy(weapon, to_weapon);
}

//default destructor for the warriors class
warriors::~warriors()
{
	if (weapon)
	{
		delete [] weapon;
	  	weapon = NULL;
	}
}

//copy constructor for the warriors class
warriors::warriors(const warriors& to_copy):character(to_copy)
{
  	strength = to_copy.strength;
  	weapon = new char[strlen(to_copy.weapon)+1];
  	strcpy(weapon, to_copy.weapon);
}

//virtual display function for the warriors class
int warriors::display_info()
{
    	cout << "CHARACTER:       " << soldier << "\n"
             << "NAME:            " << name << "\n"
             << "AGE:             " << age << "\n"
             << "WEIGHT:          " << weight << "\n"
             << "BIOGRAPHY        " << biography << "\n"
             << "STRENGTH LEVEL:  " << strength << "\n"
             << "WEAPON CHOICE:   " << weapon << "\n\n";
    
    	return 1;
}

//overloaded plus function for the warriros class
warriors operator + (const warriors& original, const warriors& to_addition)
{
  	char new_type = original.soldier[0];
  	int new_age = original.age + to_addition.age;
  	int new_weight = original.weight + to_addition.weight;
  	warriors current(new_type, original.name, original.gender, new_age, new_weight, original.biography, original.strength, original.weapon);
  	return current;
}
