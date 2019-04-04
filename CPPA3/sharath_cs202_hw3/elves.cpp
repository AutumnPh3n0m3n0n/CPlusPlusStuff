//Sharath Menon CS202 Programming Assignment 3
//this page manages the functions and prototypes for the elves class
#include "character.h"
using namespace std;

//default constructor for the elf class
elves::elves()
{
	color = NULL;
	agility = 0;
}

//extended constructor for the elf class
elves::elves(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio, char* to_color, int speed):character(type_soldier, to_name, to_gender, years, mass, bio)
{
	color = new char[strlen(to_color)+1];
	strcpy(color, to_color);
	agility = speed;
}

//default constructor for the elf class
elves::~elves()
{
	if (color)
	{
		delete [] color;
		color = NULL;
	}	
}

//copy constructor for the elf class
elves::elves(const elves& to_copy):character(to_copy)
{
  	color = new char[strlen(to_copy.color)+1];
  	strcpy(color, to_copy.color);
  	agility = to_copy.agility;
}

//virtual display function for the elf class
int elves::display_info()
{
  	cout << "CHARACTER:       " << soldier << "\n"
             << "NAME:            " << name << "\n"
             << "AGE:             " << age << "\n"
             << "WEIGHT:          " << weight << "\n"
             << "BIOGRAPHY        " << biography << "\n"
             << "COLOR:           " << color << "\n"
             << "AGILITY LEVEL:   " << agility << "\n\n";
  
  	return 1;
}

//overloaded + function for the elves class
elves operator + (const elves& original, const elves& to_addition)
{
    	char new_type = original.soldier[0];
    	int new_age = original.age + to_addition.age;
    	int new_weight = original.weight + to_addition.weight;
    	elves current(new_type, original.name, original.gender, new_age, new_weight, original.biography, original.color, original.agility);
    	return current;
}

