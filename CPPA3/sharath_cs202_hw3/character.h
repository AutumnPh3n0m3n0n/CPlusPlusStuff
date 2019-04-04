#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
//include the libraries
//this header file has the class implementations for the character class
//and all of its derived classes

class character
{
	public:
		character();
		character(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio);
		character(const character& to_copy);
		virtual ~character();
		//these are overloaded operator functionsw
		character& operator = (const character& to_copy);
		bool operator == (const character& to_compare);
		bool operator != (const character& to_compare);
		bool operator < (const character& to_compare);
		bool operator > (const character& to_compare);
		character& operator += (const int add_age);
		//friend character operator + (const character& original, const character& to_addition);
		//this is a pure virtual function
		virtual int display_info() = 0;
	protected:
		//the soldier will either be an elf or monk or hunter or orc
		char * soldier;
		char * name;
		char gender;
		int age;
		int weight;
		char * biography;
};

//the class implementation of elves and its derivation list
class elves: public character
{
	public:
		elves();
		elves(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio, char* to_color, int speed);
		elves(const elves& to_copy);
		~elves();
		int display_info();
		friend elves operator + (const elves& original, const elves& to_addition);
	private:
		char * color;
		int agility;
};

//the monk class is derived from the character class
class monks: public character
{
	public:
		monks();
		monks(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio, char* to_religion, char* place);
		monks(const monks& to_copy);
		~monks();
		int display_info();
		friend monks operator + (const monks& original, const monks& to_addition);
	private:
		char * religion;
		char * monastery;
};

//the class implementation for the warriros class
class warriors: public character
{
	public:
		warriors();
		warriors(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio, int endurance, char* to_weapon);
		warriors(const warriors& to_copy);
		~warriors();
		int display_info();
		friend warriors operator + (const warriors& original, const warriors& to_addition);
	private:
		int strength;
		char * weapon;
};

//this is the class for orcs
//orcs are seen as the bad characters while elves monks and hunters
//are seen as good characters
class orcs: public character
{
	public:
		orcs();
		orcs(char type_soldier, char* to_name, char to_gender, int years, int mass, char* bio, char* antagonist, char* place);
		orcs(const orcs& to_copy);
		~orcs();
		int display_info();
		friend orcs operator + (const orcs& original, const orcs& to_addition);
	private:
		char * enemy;
		char * tribe;
};

