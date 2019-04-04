//Sharath Menon CS202 Programming Assignment 2
#include "structures.h"
using namespace std;
//this file manages all the dunctions for the doubly linked list node class
//a doubly linked list has a dll node

//default constructor setting all pointer variable nodes to their null value
d_node::d_node()
{
	assignment = NULL;
	d_previous = NULL;
	d_next = NULL;
}

//default destructor for the dll node class
//have if conditions to prevent double free corruption
d_node::~d_node()
{
	if (assignment)
		delete assignment;
	//if (d_previous)
	//	delete d_previous;
	//if (d_next)
	//	delete d_next;
}

//function that returns the dll node previous pointer
d_node*& d_node::get_previous()
{
	return d_previous;
}

//function that returns the dll node next pointer
d_node*& d_node::get_next()
{
	return d_next;
}

//function to set the previous pointer to another dll node
void d_node::set_previous(d_node*& add_assignment)
{
	d_previous = add_assignment;
}

//function to set the next pointer to another dll node
void d_node::set_next(d_node*& add_assignment)
{
	d_next = add_assignment;	
}

//this function uses rtti to determine what specific derived class
//of the homework is being identified
void d_node::add_excersize(const homework* add_assignment)
{
	if (typeid(*add_assignment) == typeid(readings))
	{
		const readings * object = (readings*)add_assignment;
		assignment = new readings(*object);
	}
	else if (typeid(*add_assignment) == typeid(worksheets))
	{
		const worksheets * object = (worksheets*)add_assignment;
		assignment = new worksheets(*object);
	}
	else if (typeid(*add_assignment) == typeid(reports))
	{
		const reports * object = (reports*)add_assignment;
		assignment = new reports(*object);
	}
	//function to copy the contents
	//assignment->copy_contents(add_assignment);
}

//function to display the  dll node
void d_node::display_dnode()
{
	assignment->display_homework();
}
