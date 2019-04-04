//Sharath Menon CS202 Programming Assignment 2
#include "structures.h"
using namespace std;
//this file manages all the functions for the double linked list or dll
//the dll class manages all the homework assignments

//constructor for the double linked list
//set the dead and previous pointers to null
dll_manager::dll_manager()
{
	d_head = NULL;
	tail = NULL;
}

//destructor for the doubly linked list
dll_manager::~dll_manager()
{
	if (!d_head)
		cout << "There is a problem \n";
	if (d_head)
		destroy_dll_list(d_head);
}


//function to insert a dll node into the list
void dll_manager::insert_dnode(const homework* add_assignment)
{
	d_node * to_insert = new d_node;
	to_insert->add_excersize(add_assignment);
	//base case if there is not head
	if (!d_head)
	{
		d_head = to_insert;
		tail = to_insert;
	}
	//otherwise add at the beginning of the list and set head to the added node
	else
	{
		to_insert->set_next(d_head);
		d_head->set_previous(to_insert);
		d_head = to_insert;
	}
}

//function to destroy all the contents of the doubly linked list
void dll_manager::destroy_dll_list(d_node *& head)
{	//check if there is no head
	if (!head)
	{
		cout << "There is a problem. \n";
		return;
	}
	//check if the last node of the linked list;
	if (!head->get_next())
		
		delete head;
	//otherwise traverse recursively to delete the list
	else
	{
		destroy_dll_list(head->get_next());
		delete head;
	}
}

//wrapper function to display the dll list or all the assignments
void dll_manager::display_list()
{	//check is there is head
	if(d_head)
		display_list(d_head);
}

//recursive function to display the list
void dll_manager::display_list(d_node* head)
{	//if there is no next pointer  then stop
	if (!head->get_next())
		head->display_dnode();
	//display the node and traverse through the rest of the list
	else
	{
		head->display_dnode();
		display_list(head->get_next());
	}
}
