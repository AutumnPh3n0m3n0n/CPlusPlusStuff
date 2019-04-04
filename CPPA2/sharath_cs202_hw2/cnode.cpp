//Sharath Menon CS202 Programming Assignment 2
#include "homework.h"
using namespace std;
//this file manages all the functions for the circularly link list node class
//a circularly linked list has a cll node or cnode
//the circularly linked list class the the worksheet class which is 
//derived from the homework class. i ended up not having an extra
//class for the cll manager because otherwise the program will
//be very complicated with even more dynamic memory to allocate and deallocate

//default constructor for the cll node also called c_node
c_node::c_node()
{
	question = NULL;
	answered_correctly = false;
	c_next = NULL;
}

//copy constructor for the cll node
c_node::c_node(const c_node & copy_question)
{
	question = new char[strlen(copy_question.question)+1];
	strcpy(question, copy_question.question);
	answered_correctly = copy_question.answered_correctly;
	c_next = NULL;
}

//default destructor for the cll node
//have an if condition to prevent double free corruption
c_node::~c_node()
{
	if (question)
		delete [] question;
	//if (c_next)
	//	delete c_next;
}

//getter function to return the cll node next pointer
c_node*& c_node::get_next()
{
	return c_next;
}

//setter function to set the cll node next pointer
void c_node::set_next(c_node*& set_question)
{
	c_next = set_question;
}

//function to initialize the variables
void c_node::set_question(char* add_question, char the_answer)
{
	question = new char[strlen(add_question)+1];
	strcpy(question, add_question);
	//set the answered correctly variable
	if (the_answer != 'N')
		answered_correctly = true;
	else
		answered_correctly = false;
}

//function to display the cll node
void c_node::display_node()
{
	cout << "Question:      " << question << "\n";
	if (answered_correctly == true)
		cout << "Correct! \n\n";
	else
		cout << "Incorrect! \n\n";
}

//function to set the next pointer to null;
void c_node::set_next_null()
{
	c_next = NULL;
}
