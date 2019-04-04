//Sharath Menon CS202 Programming Assignemnt 3
//this page manages the functions and prototypes for the monk class
#include "character.h"
using namespace std;

//default constructor for monks
monks::monks()
{
	religion = NULL;
	monastery = NULL;
}

//extended constructor for monks
monks::monks(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio, char* to_religion, char* place):character(type_soldier, to_name, to_gender, years, mass, bio)
{
	religion = new char[strlen(to_religion)+1];
	strcpy(religion, to_religion);
	monastery = new char[strlen(place)+1];
	strcpy(monastery, place);
}

//default destructor for monks
monks::~monks()
{
	if (religion)
	{
		delete [] religion;
	  	religion = NULL;
	}
	if (monastery)
	{
		delete [] monastery;
	  	monastery = NULL;
  	}
}

//copy constructor for monks
monks::monks(const monks& to_copy):character(to_copy)
{
  	religion = new char[strlen(to_copy.religion)+1];
  	strcpy(religion, to_copy.religion);
  	monastery = new char[strlen(to_copy.monastery)+1];
  	strcpy(monastery, to_copy.monastery);
}

//virtual display function for the monk class
int monks::display_info()
{
  	cout << "CHARACTER:       " << soldier << "\n"
             << "NAME:            " << name << "\n"
             << "AGE:             " << age << "\n"
             << "WEIGHT:          " << weight << "\n"
             << "BIOGRAPHY        " << biography << "\n"
             << "RELIGION:        " << religion << "\n"
             << "MONASTERY:       " << monastery << "\n\n";
  
  	return 1;
}

//overloaded + operator for the monk class
monks operator + (const monks& original, const monks& to_addition)
{
  	char new_type = original.soldier[0];
  	int new_age = original.age + to_addition.age;
  	int new_weight = original.weight + to_addition.weight;
  	monks current(new_type, original.name, original.gender, new_age, new_weight, original.biography, original.religion, original.monastery);
  	return current;
}
