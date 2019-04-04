//Sharath Menon CS202 Programming Assignment 1
#include "structures.h"
using namespace std;
//functions for the linear linked list (lll) nodes

//default constructor for the lll node
l_node::l_node()
{
	//info = NULL;
	l_next = NULL;
}

//default destructor for the lll node 
l_node::~l_node()
{
	l_next = NULL;
}

//for the copy constructor for the lll node copy the information over
//but have the next pointer set to null
l_node::l_node(const l_node& copy_order)
{
	info = delivery(copy_order.info);
	l_next = NULL;
}

//function to return the lll node next pointer
l_node*& l_node::get_next()
{
	return l_next;
}

//function to set the lll node next pointer taking in another 
//lll node as an argument
void l_node::set_next(l_node*& to_next)
{
	l_next = to_next;
}

//function to display the lll node that utilized the getter functions
//from the route and delivery class
void l_node::display_lnode()
{
	cout << "ORDER TAG INFORMATION   \n";
	cout << "Type of Order:		 " << info.get_type() << "\n";
	cout << "Person Name:	         " << info.get_name() << "\n";
	cout << "Warehouse Address:      " << info.get_warehouse() << "\n";
	cout << "Delivery Address:       " << info.get_dest_address() << "\n";
	cout << "Number of Orders:    	 " << info.get_number() << "\n";
	cout << "Total Cost:		 " << info.get_cost() << "\n\n";
}

//assign the information to the delivery using the copy constructor
void l_node::set_info(const delivery& add_order)
{
	info.copy_deliver(add_order); 
}

//the functions for the circular linked list (cll)
//default constructor for the cll node
c_node::c_node()
{
	//pathway = NULL;
	track_number = 0;
	c_next = NULL;
}

//the destructor for the cll node deletes the pointers
c_node::~c_node()
{
	//if (pathway)
	//	delete pathway;
	//pathway = NULL;
	c_next = NULL;
}

//function to set the cll node next pointer
void c_node::set_next(c_node*& to_next)
{
	c_next = to_next;
}

//function to get the next pointer of the cll node
c_node*& c_node::get_next()
{
	return c_next;
}

//function to set the foute information into the cll node
void c_node::set_info(const route& set_route, int order_number)
{
	track_number = order_number;
	pathway.copy_contents(set_route);
}

//function to set the cll node next pointer to null
void c_node::set_next_null()
{
	c_next = NULL;
}

//copy copnstructor for the cll node
c_node::c_node(const c_node& copy_order)
{
	pathway = route(copy_order.pathway);
	track_number = copy_order.track_number;
	c_next = NULL;
}

//function to display the contents of the cll node
void c_node::display_cnode()
{
	cout << "Tracking Number:         " << track_number << "\n";
	cout << "Departure Address:       " << pathway.get_warehouse() << "\n";
	cout << "Destination Address:     " << pathway.get_dest_address() << "\n\n";
}
