//Sharath Menon CS202 Programming Assignment 1
#include "structures.h"
using namespace std;
//this file manages the functions for both the linear and circular
//linked list data structures

//dault constructor for the lll data structure or manager
lll_manager::lll_manager()
{
	num_of_orders = 0;
	l_head = NULL;
	l_tail = NULL;
}

//destructor for the linear linked list calls the wrapper
lll_manager::~lll_manager()
{
	if (l_head != NULL)
		delete_all(l_head);
}

//wrapper function to delete all the lll contents recursively
void lll_manager::delete_all(l_node*& current)
{
	if (!current->get_next())
		delete current;
	else
	{
		delete_all(current->get_next());
		delete current;
	}
}

//wrapper function to display the lll list
void lll_manager::display_lll_list()
{
	display_lll_list(l_head);
}

//function to display the lll
void lll_manager::display_lll_list(l_node*& current)
{	//stopping condition
	if (!current->get_next())
		current->display_lnode();
	//otherwise traverse the list recursively
	else
	{
		current->display_lnode();
		display_lll_list(current->get_next());
	}
}

//function to insert a lll node into the lll list
void lll_manager::insert_order(const delivery& add_order)
{	//make a new node and copy the contents
	l_node* to_insert = new l_node;
	to_insert->set_info(add_order);
	if(!l_head)
	{	//if there is no head set head to the node
		l_head = to_insert;
		l_tail = l_head;
		++num_of_orders;
	}
	else
	{	//otherwise add at the tail pointer
		l_tail->set_next(to_insert);
		l_tail = to_insert;
		++num_of_orders;
	}
}

//function to obtain the number of nodes or orders
int lll_manager::get_num_orders()
{
	return num_of_orders;
}

//the functions for the cll data structure
//default constructor for the cll setting all data members to their zero equivalent
cll_manager::cll_manager()
{
	num_of_paths = 0;
	c_head = NULL;
	c_tail = NULL;
}

//destructor for the cll
cll_manager::~cll_manager()
{
	c_tail->set_next_null();
	delete_all(c_head);
	c_head = NULL;
	c_tail = NULL;
}

//function to remove all contents from a cll recursively
void cll_manager::delete_all(c_node*& current)
{	//check if the last node is null as a stopping condition
	if (!current->get_next())
		delete current;
	//otherwise delete the list recursively
	else
	{
		delete_all(current->get_next());
		delete current;
	}
}

//function to insert a node into the circularly linked list
void cll_manager::insert_node(const route& add_order, int order_number)
{
	//make a new cll node
	c_node * to_insert = new c_node;
	//add the contents
	to_insert->set_info(add_order, order_number);
	//if there is not head then set the head pointer to the node being inserted
	if(!c_head)
	{
		c_head = to_insert;
		c_tail = c_head;
		c_tail->set_next(c_head);
	}
	//otherwise add at the end of the list and close the list back up
	else
	{
		to_insert->set_next(c_head);
		c_tail->set_next(to_insert);
		c_tail = to_insert;
	}
}

//wrapper function to display the cll
void cll_manager::display_cll_list()
{
	//for safety purposes in case there is no tail node
	if (!c_tail || !c_head)
		cout << "ERROR!" << endl;
	else
	{
		//cut the cll into a lll
		c_tail->set_next_null();
		//traverse the list recursively
		display_cll_list(c_head);
		//close the list back up into a cll again
		c_tail->set_next(c_head);
	}
}

//function to display the cll list
void cll_manager::display_cll_list(c_node*& current)
{	//stopping condition
	if(!current->get_next())
		current->display_cnode();
	else
	{
		current->display_cnode();
		display_cll_list(current->get_next());
	}
}
