//Sharath Menon CS202 Programming Assignment 2
#include "homework.h"
using namespace std;
//this file manages the functions for the readings class
//the readings class is derived from the homework class

//default constructor for the readings class
//which has an initialization list for the homework constructor
readings::readings():homework()
{
	textbook = NULL;
	author = NULL;
	chapter = 0;
	pages = 0;
}

//default constructor for the reading class
readings::~readings()
{
	delete [] textbook;
	delete [] author;
}

//copy constructor for readings
readings::readings(const readings& copy_assignment)
{
	textbook = new char[strlen(copy_assignment.textbook)+1];
	strcpy(textbook, copy_assignment.textbook);
	author = new char[strlen(copy_assignment.author)+1];
	strcpy(author, copy_assignment.author);
	chapter = copy_assignment.chapter;
	pages = copy_assignment.pages;
	score = copy_assignment.score;
	if_completed = copy_assignment.if_completed;
}

//bounded function from homework to display the reading assignment
void readings::display_homework()
{
	cout << "Textbook:    " << textbook << "\n"
	     << "Author:      " << author << "\n"
	     << "Chapter:     " << chapter << "\n"
	     << "Pages:       " << pages << "\n";
	//the homework is completed if the score is 70 or above
	if (get_score() > 70)
		cout << "Completed:   YES \n\n";
	else
		cout << "Completed:   NO \n\n";
}


//the virtual copy constructor for the readings class
void readings::copy_contents(const homework& to_copy)
{/*
	textbook = new char[strlen(to_copy.textbook)+1];
	strcpy(textbook, to_copy.textbook);
	author = new char[strlen(to_copy.author)+1];
	strcpy(author, to_copy.author);
	chapter = to_copy.chapter;
	pages = to_copy.pages;
	set_score_completed(to_copy.score);*/
}

//function toi copy the contents into the readings class
void readings::copy_contents(const readings& to_copy)
{
	textbook = new char[strlen(to_copy.textbook)+1];
	strcpy(textbook, to_copy.textbook);
	author = new char[strlen(to_copy.author)+1];
	strcpy(author, to_copy.author);
	chapter = to_copy.chapter;
	pages = to_copy.pages;
	//this function sdetermins the completion based on score
	set_score_completed(to_copy.score);
}

//extended constructor that initiazlizes the variables
readings::readings(char* text, char* writer, int section, int page, int percentage)
{
	textbook = new char[strlen(text)+1];
	strcpy(textbook, text);
	author = new char[strlen(writer)+1];
	strcpy(author, writer);
	chapter = section;
	pages = page;
	set_score_completed(percentage);
}
