//Sharath Menon CS202 Programming Assignment 3
#include "character.h"
using namespace std;

//default constructor for character
character::character()
{
	soldier = NULL;
	name = NULL;
	gender = '\0';
	age = 0;
	weight = 0;
	biography = NULL;
}

//delerte all dynamic memory
character::~character()
{
	if (soldier)
	{
		delete [] soldier;
		soldier = NULL;
	}
	if (name)
	{	
		delete [] name;
		name = NULL;
	}
	if (biography)
	{
		delete [] biography;
		biography = NULL;
	}
}

//extended constructor for character
character::character(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio)
{
	if (type_soldier == 'E')
	{
		soldier = new char[4];
		strcpy(soldier, "Elf");
	}
	if (type_soldier == 'M')
	{
		soldier = new char[5];
		strcpy(soldier, "Monk");
	}
	if (type_soldier == 'W')
	{
		soldier = new char[7];
		strcpy(soldier, "Warrior");
	}
	if (type_soldier == 'O')
	{
		soldier = new char[5];
		strcpy(soldier, "Orcs");
	}
	name = new char[strlen(to_name)+1];
	strcpy(name, to_name);
	gender = to_gender;
	age = years;
	weight = mass;
	biography = new char[strlen(bio)+1];
	strcpy(biography, bio);
}

//copy constructor for the character class
character::character(const character& to_copy)
{
	soldier = new char[strlen(to_copy.soldier)+1];
	strcpy(soldier, to_copy.soldier);
  	name = new char[strlen(to_copy.name)+1];
  	strcpy(name, to_copy.name);
  	gender = to_copy.gender;
  	age = to_copy.age;
  	weight = to_copy.weight;
  	biography = new char[strlen(to_copy.biography)+1];
  	strcpy(biography, to_copy.biography);
}

character& character::operator = (const character& to_copy)
{
	if (soldier)
		delete [] soldier;
	soldier = new char[strlen(to_copy.soldier)+1];
  	strcpy(soldier, to_copy.soldier);
  	
	if (name)
		delete [] name;
  	name = new char[strlen(to_copy.name)+1];
  	strcpy(name, to_copy.name);

  	gender = to_copy.gender;
	age = to_copy.age;
  	weight = to_copy.weight;
  	
  	if (biography)
  		delete [] biography;
  	biography = new char[strlen(to_copy.biography)+1];
  	strcpy(biography, to_copy.biography);
  	
  	return *this;
}

bool character::operator == (const character& to_compare)
{
	if (strcmp(soldier, to_compare.soldier) != 0)
		return false;
	if (strcmp(name, to_compare.name) != 0)
		return false;

	return true;
}

bool character::operator != (const character& to_compare)
{
  if (strcmp(soldier, to_compare.soldier) == 0)
    return false;
  if (strcmp(name, to_compare.name) == 0)
    return false;
  
  return true;
}

bool character::operator < (const character& to_compare)
{
    if (strcmp(name, to_compare.name) >= 0)
        return false;
      
    return true;
}
bool character::operator > (const character& to_compare)
{
    if (strcmp(name, to_compare.name) <= 0)
        return false;
  
    return true;
}

character& character::operator += (const int add_age)
{
    age += add_age;
    return *this;
}

/*
character operator + (const character& original, const character& to_addition)
{
    char new_type = original.soldier[0];
    int new_age = original.age + to_addition.age;
    int new_weight = original.weight + to_addition.weight;
    character current(new_type, original.name, original.gender, new_age, new_weight, original.biography);
    return current;
}*/
