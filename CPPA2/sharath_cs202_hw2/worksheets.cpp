//Sharath Menon CS202 Programming Assignment 2
#include "homework.h"
using namespace std;
//this is a large class on its own because the worksheets serve to be a
//circular linked list or cll class. i did not make a separate cll class
//or the program will become much more complicated with more dynamic memory 
//to allocate. the worksheets class is also derived from the homework class

//default constructor for the homework class
worksheets::worksheets():homework()
{
	topic = NULL;
	num_of_questions = 0;
	rear = NULL;
	c_head = NULL;
}

//default destructor for the worksheets class
worksheets::~worksheets()
{
	if (topic)
		delete [] topic;
	//if there is a rear pointer
	//then destroy the list
	if (c_head)
	{
		rear->set_next_null();
		destroy_cll(c_head);
	}
}

//copy constructor for the worksheets class
worksheets::worksheets(const worksheets& copy_assignment)
{
	topic = new char[strlen(copy_assignment.topic)+1];
	strcpy(topic, copy_assignment.topic);
	num_of_questions = copy_assignment.num_of_questions;
	score = copy_assignment.score;
	if_completed = copy_assignment.if_completed;
	rear = NULL;
	c_head = NULL;

}

//function to set the worksheets class
worksheets::worksheets(char* idea, int question_num, int points)
{
	topic = new char[strlen(idea)+1];
	strcpy(topic, idea);
	num_of_questions = question_num;
	set_score_completed(points);
	c_head = NULL;
	rear = NULL;
}

//code to destroy the cll list
void worksheets::destroy_cll(c_node *& head)
{
	if (!head->get_next())
	{
		head->set_next_null();
		delete rear;
	}
	else
	{
		destroy_cll(head->get_next());
		delete head;
	}
}

//code to insert a node into the cll list
void worksheets::insert_question(char* add_question, char the_answer)
{	//create a new cll node and set the contents to it
	c_node * to_insert = new c_node;
	to_insert->set_question(add_question, the_answer);
	//if there is no head pointer in the list 
	//set the head pointer equal to the added node
	//then set the tail pointer and have the node point to itself
	if (!c_head)
	{
		c_head = to_insert;
		rear = to_insert;
		rear->set_next(c_head);
	}
	//otherwise set rear to point at the added cll node and
	//the added node to point at head. then set rear to the added node
	else
	{
		rear->set_next(to_insert);
		to_insert->set_next(c_head);
		rear = to_insert;
	}
}


//bounded function from the homework class to copy the 
//contents over
//if i had more time to work on this assignment
//the copy cll feature would be here
void worksheets::copy_contents(const homework& to_copy)
{
	//topic = new char[strlen(to_copy.topic)+1];
	//strcpy(topic, to_copy.topic);
	//c_head = NULL;
	//rear = NULL;
	//set_score_completed(to_copy.score);
}


void worksheets::copy_contents(const worksheets& to_copy)
{
	topic = new char[strlen(to_copy.topic)+1];
	strcpy(topic, to_copy.topic);
	set_score_completed(to_copy.score);
	c_head = NULL;
	rear = NULL;
}

void worksheets::display_homework()
{
	cout << "Topic:                 " << topic << "\n"
	     << "Number of Questions:   " << num_of_questions << "\n";
	if (!c_head)
		cout << "There are no questions to show here! \n\n";
	else
	{
		//disconnect the cll list by disabling the rear next pointer
		rear->set_next_null();
		//traverse recursively
		display_cll_list(c_head);
		//close the cll back up again
		rear->set_next(c_head);
	}
}

void worksheets::display_cll_list(c_node* head)
{
	if (!head)
		return;
	else
	{
		head->display_node();
		display_cll_list(head->get_next());
	}
}
