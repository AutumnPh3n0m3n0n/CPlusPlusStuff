//Sharath Menon CS202 Programming Assignment 2
#include "homework.h"
using namespace std;
//this file manages the functions for the report class
//the report class is derived from the homework class

//default constructor for reports
reports::reports():homework()
{
	title = NULL;
	pages = 0;
	words = 0;
}

//default destructor for reports
//check for 
reports::~reports()
{
	if (title)
		delete [] title;
}

//copy constructor for reports that copies the variables
reports::reports(const reports& copy_assignment)
{
	title = new char[strlen(copy_assignment.title)+1];
	strcpy(title, copy_assignment.title);
	pages = copy_assignment.pages;
	words = copy_assignment.words;
	pages = copy_assignment.pages;
	if_completed = copy_assignment.if_completed;
}

//an extended constructor to initialize the reports class 
reports::reports(char* idea, int page, int word_count, int score)
{
	title = new char[strlen(idea)+1];
	strcpy(title, idea);
	pages = page;
	words = word_count;
	set_score_completed(score);
}

//bounded function from the homework class TO THE DERIVED REPORTS CLASS
void reports::display_homework()
{
	cout << "Essay Topic:          " << title << "\n"
	     << "Number of Pages:      " << pages << "\n"
	     << "Number of WOrds:      " << words << "\n"
	     << "Score:                " << score << "\n\n";
}

void reports::copy_contents(const homework& to_copy)
{
	//title = new char[strlen(to_copy
	//pages = to_copy.pages;
	//words = to_copy.words;
	//score = to_copy.score;
	//if_completed = to_copy.if_completed;
}

//another copy contents function
void reports::copy_contents(const reports& to_copy)
{
	title = new char[strlen(to_copy.title)];
	strcpy(title, to_copy.title);
	pages = to_copy.pages;
	words = to_copy.words;
	set_score_completed(to_copy.score);
}
