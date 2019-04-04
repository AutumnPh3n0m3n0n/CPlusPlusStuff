//Sharath Menon Programming Assignment 3
//This file manages the orcs class functions
#include "character.h"
using namespace std;

//default constructor for the orcs class
orcs::orcs()
{
  	enemy = NULL;
	tribe = NULL;
}

//copy constructor for the orcs class
orcs::orcs(const orcs& to_copy):character(to_copy)
{
  	enemy = new char[strlen(to_copy.enemy)+1];
  	strcpy(enemy, to_copy.enemy);
  	tribe = new char[strlen(to_copy.tribe)+1];
  	strcpy(tribe, to_copy.tribe);
}

//extended contructor for the orcs class
orcs::orcs(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio, char* antagonist, char* place):character(type_soldier, to_name, to_gender, years, mass, bio)
{
  	enemy = new char[strlen(antagonist)+1];
  	strcpy(enemy, antagonist);
  	tribe = new char[strlen(place)+1];
  	strcpy(tribe, place);
}

//destructor for the orcs class
orcs::~orcs()
{
  	if (enemy)
  	{
    		delete [] enemy;
  	    	enemy = NULL;
  	}
  	if (tribe)
  	{
    		delete [] tribe;
  	    	tribe = NULL;
  	}
}

//virtual display function for the orcs class
int orcs::display_info()
{
  	cout << "CHARACTER:       " << soldier << "\n"
       	     << "NAME:            " << name << "\n"
       	     << "AGE:             " << age << "\n"
             << "WEIGHT:          " << weight << "\n"
             << "BIOGRAPHY        " << biography << "\n"
             << "ENEMY GROUP:     " << enemy << "\n"
             << "TRIBE:           " << tribe << "\n\n";
  
  	return 1;
}

//overloaded plus function for the orcs class
orcs operator + (const orcs& original, const orcs& to_addition)
{
  	char new_type = original.soldier[0];
  	int new_age = original.age + to_addition.age;
  	int new_weight = original.weight + to_addition.weight;
  	orcs current(new_type, original.name, original.gender, new_age, new_weight, original.biography, original.enemy, original.tribe);
  	return current;
}
