//Sharath Menon CS202 Programming Assignment 3
//THis is the main file for the third programming assignment
#include "structures.h"
using namespace std;

int main()
{
	//build the data structure
	tree_23 Data_Struct;
	//this character class pointer 
	character * to_insert = NULL;
	char type_soldier, to_gender, again;
	int years, mass, speed, endurance, count;
	count = 0;
	//have a scaracter array to store in and transfer the day 
	char collect[101];
	//the character arrays being used
	char * to_name;
	char * bio;
	char * to_color;
	char * to_religion;
	char * place;
	char * to_weapon;
	char * antagonist;
	//the instructions
	cout << "Welcome to a program where you can create your video game characters\n" 
	     << "and the program will store in the character for you. \n\n"
	     << "The types of video game characters are: Elves, Monks, Warriors, and Orcs. \n"
	     << "Elves, Monks, and Warriors are the good characters or protagonists. \n"
	     << "Orcs are the evil characters or antagonists. \n"
	     << "Although there have been moments in history where Orcs have saved the \n"
	     << "Monks from ivading Elves and Warriors, and Elves from invading Warriors. \n\n"
	     << "To create an Elf, type E \n"
	     << "To create a Monk, type M \n"
	     << "To create a Warrior, type W \n"
	     << "To create an Orc, type O \n";
	//the do while loop will let users keep entering information into the tree
	do { 
	//the nested do while loops prevent users from entering in nonsense information
	do {
		cout << "\n\n Please enter in your character below:   ";
		cin >> type_soldier;
		cin.ignore(10, '\n');
		type_soldier = toupper(type_soldier);
		if (type_soldier != 'E' && type_soldier != 'M' && type_soldier != 'W' && type_soldier != 'O')
			cout << "Please enter either: E (ELf), M (Monk), W (Warrior), O (Orc) " << endl;
	   } while (type_soldier != 'E' && type_soldier != 'M' && type_soldier != 'W' && type_soldier != 'O');
	
	cout << "What is the name of your character:   ";
	cin.get(collect, 41, '\n');
	cin.ignore(30, '\n');
	to_name = new char[strlen(collect)+1];
	strcpy(to_name, collect);
	//capitalize the first letter for assignment operator purposes
	to_name[0] = toupper(to_name[0]);

	do {
		cout << "How old is this character? ENTER A NUMBER between 1 and 100:   ";
		cin >> years;
		cin.ignore(10, '\n');
	   } while (years <= 1 || years >= 100);
  	do {
   		cout << "Is you character male (M) or female (F):   ";
    		cin >> to_gender;
    		cin.ignore(10, '\n');
    		to_gender = toupper(to_gender);
  	   } while (to_gender != 'M' && to_gender != 'F');
	do {
   		cout << "How much does the character weigh (ENTER A NUMBER between 30 and 500):   ";
    		cin >> mass;
    		cin.ignore(10, '\n');
    		to_gender = toupper(to_gender);
  	   } while (mass < 30 || to_gender > 500);
	cout << "What is the characters backstory?   ";
	cin.get(collect, 101, '\n');
	cin.ignore(50, '\n');
	bio = new char[strlen(collect)+1];
	strcpy(bio, collect);
	++ count;
	if (type_soldier == 'E')
	{	//for the elf class
		cout << "Your character is an Elf. What color is your elf?   ";
		cin.get(collect, 21, '\n');
		cin.ignore(20, '\n');
		to_color = new char[strlen(collect)+1];
		strcpy(to_color, collect);
		do {
			cout << "What is the agility or speed level of your elf? ENTER A NUMBER between 1 (very slow) to 10 (very fast)   ";
			cin >> speed;
			cin.ignore(10, '\n');
		   } while (speed < 1 || speed > 10);
		//make a dynamic elf object from character pointer
		to_insert = new elves(type_soldier, to_name, to_gender, years, mass, bio, to_color, speed);
		Data_Struct.insert_character(to_insert);
		delete [] to_color;
		delete to_insert;
	}
	else if (type_soldier == 'M')
	{	//for the monk class
		cout << "Your character is a Monk. What religion is your monk?   ";
		cin.get(collect, 21, '\n');
		cin.ignore(20, '\n');
		to_religion = new char[strlen(collect)+1];
		strcpy(to_religion, collect);
		cout << "What monastery does your monk reside?   ";
		cin.get(collect, 21, '\n');
		cin.ignore(20, '\n');
		place = new char[strlen(collect)+1];
		strcpy(place, collect);
		//store information into the data structure and delete all dynamic memory
		to_insert = new monks(type_soldier, to_name, to_gender, years, mass, bio, to_religion, place);
		Data_Struct.insert_character(to_insert);
		delete [] to_religion;
		delete [] place;
		delete to_insert;
	}
	else if (type_soldier == 'W')
	{	//for the warriro class
		cout << "Your character is a Warrior. What is the primary weapon for your warrior?   ";
		cin.get(collect, 31, '\n');
		cin.ignore(20, '\n');
		to_weapon = new char[strlen(collect)+1];
		strcpy(to_weapon, collect);
		do {
			cout << "What is the agility or speed level of your elf? ENTER A NUMBER between 1 (very slow) to 10 (very fast)   ";
			cin >> endurance;
			cin.ignore(10, '\n');
		   } while (endurance < 1 || endurance > 10);
		//store information into the data structure
		to_insert = new warriors(type_soldier, to_name, to_gender, years, mass, bio, endurance, to_weapon);
		Data_Struct.insert_character(to_insert);
		delete [] to_weapon;
		delete to_insert;
	}
	else if (type_soldier == 'O')
	{	//for the orc class
		cout << "Your character is an Orc, so you must like the villains. Which character does your orc consider an enemy?   ";
		cin.get(collect, 21, '\n');
		cin.ignore(20, '\n');
		antagonist = new char[strlen(collect)+1];
		strcpy(antagonist, collect);
		cout << "What is the Orc's tribes name?   ";
		cin.get(collect, 21, '\n');
		cin.ignore(20, '\n');
		place = new char[strlen(collect)+1];
		strcpy(place, collect);
		//store information into data structure
		to_insert = new orcs(type_soldier, to_name, to_gender, years, mass, bio, antagonist, place);
		Data_Struct.insert_character(to_insert);
		delete [] antagonist;
		delete [] place;
		delete to_insert;
	}
	//delete this memory to prevent memory leaks
	delete [] to_name;
	delete [] bio;
	//ask the user if they would like to enter in another character
	cout << "You have entered " << count << " entries. Would you like to enter in another order? (Press N or S to stop)   ";
	cin >> again;
	cin.ignore(10, '\n');
	again = toupper(again);
	} while (again != 'N' && again != 'S');
	//display the characers
	cout << "Here are the list of " << count << " characters \n";
	Data_Struct.display_all();	
	return 1;
}
