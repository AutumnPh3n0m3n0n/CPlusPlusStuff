//Sharath Menon CS202 Programming Assignment 1
#include "delivery.h"
using namespace std;

//default constructor for route class
route::route()
{
	wh_address = NULL;
	deliver_address = NULL;
}

//default constructor for route class
route::~route()
{
	if (wh_address)
		delete [] wh_address;
	if (deliver_address)
		delete [] deliver_address;
}

//copy constructor for the orders class
route::route(const route& to_copy)
{
	wh_address = new char[strlen(to_copy.wh_address)+1];
	strcpy(wh_address, to_copy.wh_address);
	deliver_address = new char[strlen(to_copy.deliver_address)+1];
	strcpy(deliver_address, to_copy.deliver_address);
}

//extended constructor for the route class
route::route(char* warehouse, char* deliver)
{
	wh_address = new char[strlen(warehouse)+1];
	strcpy(wh_address, warehouse);
	deliver_address = new char[strlen(deliver)+1];
	strcpy(deliver_address, deliver);
}

//this function was made because the copy constructor for some reason was not working when
//it was called when storing the contents in the cll node
void route::copy_contents(const route& to_copy)
{
	wh_address = new char[strlen(to_copy.wh_address)+1];
	strcpy(wh_address, to_copy.wh_address);
	deliver_address = new char[strlen(to_copy.deliver_address)+1];
	strcpy(deliver_address, to_copy.deliver_address);
}

char*& route::get_warehouse()
{
	return wh_address;
}

char*& route::get_dest_address()
{
	return deliver_address;
}

//default constructor for the delivery class
delivery::delivery():route()
{
	order_type = NULL;
	order_name = NULL;
	num_of_orders = 0;
	cost = 0.00;
}

//destructor for the delivery class
delivery::~delivery()
{
	if (order_type)
		delete [] order_type;
	if (order_name)
		delete [] order_name;
}

//extended constructor for the delivery class which goes up to the route class
delivery::delivery(char* warehouse, char* deliver, char* name, int orders, float charge, char* type):route(warehouse, deliver)
{
	order_type = new char[strlen(type)+1];
	strcpy(order_type, type);	
	order_name = new char[strlen(name)+1];
	strcpy(order_name, name);
	num_of_orders = orders;
	cost = charge;
}

//this function is there to copy the contents
void delivery::copy_delivery(char* warehouse, char*deliver, char* name, int orders, float charge, char* type)
{
	wh_address = new char[strlen(warehouse)+1];
	strcpy(wh_address, warehouse);
	deliver_address = new char[strlen(deliver)+1];
	strcpy(deliver_address, deliver);
	order_type = new char[strlen(type)+1];
	strcpy(order_type, type);	
	order_name = new char[strlen(name)+1];
	strcpy(order_name, name);
	num_of_orders = orders;
	cost = charge;
}

//this additional function was written since the lll node was failing to get the contents
void delivery::copy_deliver(const delivery& to_copy)
{
	wh_address = new char[strlen(to_copy.wh_address)+1];
	strcpy(wh_address, to_copy.wh_address);
	deliver_address = new char[strlen(to_copy.deliver_address)+1];
	strcpy(deliver_address, to_copy.deliver_address);
	order_type = new char[strlen(to_copy.order_type)+1];
	strcpy(order_type, to_copy.order_type);	
	order_name = new char[strlen(to_copy.order_name)+1];
	strcpy(order_name, to_copy.order_name);
	num_of_orders = to_copy.num_of_orders;
	cost = to_copy.cost;
}

//copy constructor for the delivery class
delivery::delivery(const delivery& copy_order):route(copy_order)
{
	order_type = new char[strlen(copy_order.order_type)+1];
	strcpy(order_type, copy_order.order_type);
	order_name = new char[strlen(copy_order.order_name)+1];
	strcpy(order_name, copy_order.order_name);
	num_of_orders = copy_order.num_of_orders;
	cost = copy_order.cost;
}

//getter function for displaying the cost
float delivery::get_cost()
{
	return cost;
}

//getter function for displaying the name
char*& delivery::get_name()
{
	return order_name;
}

//getter function for displaying the type
char*& delivery::get_type()
{
	return order_type;
}

//getter function for displaying the number
int delivery::get_number()
{
	return num_of_orders;
}
