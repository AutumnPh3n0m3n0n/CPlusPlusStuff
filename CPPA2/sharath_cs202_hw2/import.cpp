//Sharath Menon CS202 Programming Assignment 2
#include "structures.h"
using namespace std;

//function to import the readings
void dll_manager::import_readings()
{	//name the import function import 1
	ifstream import_1;
	char to_get[40];
	char * text;
	char * writer;
	int chapter, page, percentage;
	readings* to_insert_dll = NULL;

	import_1.open("readings.txt");
	while (!import_1.eof())
	{	//import the variables from the test file
		import_1.get(to_get, 40, ';');
		import_1.ignore(20, ';');
		text = new char[strlen(to_get)+1];
		strcpy(text, to_get);

		import_1.get(to_get, 20, ';');
		import_1.ignore(20, ';');
		writer = new char[strlen(to_get)+1];
		strcpy(writer, to_get);

		import_1 >> chapter;
		import_1.ignore(10, ';');
		import_1 >> page;
		import_1.ignore(10, ';');
		import_1 >> percentage;
		import_1.ignore(10, '\n');
		//create a new class importing the variables
		//then insert into the dll
		to_insert_dll = new readings(text, writer, chapter, page, percentage);
		insert_dnode(to_insert_dll);
		//delete dynamic memory to get rid of memory leaks
		delete [] text;
		delete [] writer;
		delete to_insert_dll;
	}
}

//function to import the worksheets
void dll_manager::import_worksheets()
{	//name the import function import 2
	ifstream import_2;
	char to_get[60];
	char * idea;
	char * question_1;
	char * question_2;
	char * question_3;
	int question_num;
	int points;
	char correct_1, correct_2, correct_3;
	worksheets* to_insert_dll = NULL;
	import_2.open("worksheets.txt");
	while(!import_2.eof())
	{
		import_2.get(to_get, 20, ';');
		import_2.ignore(20, ';');
		idea = new char[strlen(to_get)+1];
		strcpy(idea, to_get);

		import_2 >> question_num;
		import_2.ignore(10, ';');

		import_2.get(to_get, 60, ';');
		import_2.ignore(20, ';');
		question_1 = new char[strlen(to_get)+1];
		strcpy(question_1, to_get);

		import_2.get(to_get, 60, ';');
		import_2.ignore(20,';');
		question_2 = new char[strlen(to_get)+1];
		strcpy(question_2, to_get);

		import_2.get(to_get, 60, ';');
		import_2.ignore(20, ';');
		question_3 = new char[strlen(to_get)+1];
		strcpy(question_3, to_get);
		
		import_2 >> correct_1;
		import_2.ignore(10, ';');
		import_2 >> correct_2;
		import_2.ignore(10, ';');
		import_2 >> correct_3;
		import_2.ignore(10, ';');
		import_2 >> points;
		import_2.ignore(10, '\n');
		to_insert_dll = new worksheets(idea, question_num, points);
		//insert questions into the cll
		to_insert_dll->insert_question(question_1, correct_1);
		to_insert_dll->insert_question(question_2, correct_2);
		to_insert_dll->insert_question(question_3, correct_3);
		//insert into the dll
		insert_dnode(to_insert_dll);

		//delete dynamic memory to prevent memory leaks
		delete [] idea;
		delete [] question_1;
		delete [] question_2;
		delete [] question_3;
		delete to_insert_dll;
	}
}

//function to import the essays into the dll
void dll_manager::import_essays()
{	//name the ifstream function import 3
	ifstream import_3;
	char * idea;
	int pages, words, score;	
	char to_get[20];
	reports* to_insert_dll = NULL;
	import_3.open("essay.txt");
	while(!import_3.eof())
	{	//import the variables
		import_3.get(to_get, 20, ';');
		import_3.ignore(20, ';');
		idea = new char[strlen(to_get)+1];
		strcpy(idea, to_get);

		import_3 >> pages;
		import_3.ignore(10, ';');
		import_3 >> words;
		import_3.ignore(10, ';');
		import_3 >> score;
		import_3.ignore(10, '\n');
		//create a reports class with the variables
		to_insert_dll = new reports(idea, pages, words, score);
		insert_dnode(to_insert_dll);
		//delete the memory to prevent memory leaks
		delete [] idea;
		delete to_insert_dll;
	}
}
