//Sharath Menon CS202 Programming Assignment 1
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <time.h>
#include <stdlib.h>

//this headewr file is for all the hierarchy classes
//the route class is at the top of this hierarchy
//a virtual destructor is used to get red of memory leaks
//since static binding was used

class route
{
	public:
		route();
		virtual ~route();
		route(const route& copy_order);
		//this extended constructor works as a setter to initialize the variables
		route(char* warehouse, char* deliver);
		void copy_contents(const route& copy_route);
		//these getter functions to obtain the character array for displaying the node
		char*& get_warehouse();
		char*& get_dest_address();
	protected:
		char* wh_address;	//wh is short for warehouse
		char* deliver_address;	//have a delivery address
};

//delivery class which is derived from the route class
class delivery: public route
{
	public:
		delivery();
		virtual ~delivery();
		delivery(const delivery& copy_order);
		delivery(char* warehouse, char* deliver, char* name, int orders, float charge, char* type);
		float get_cost();
		char*& get_name();
		char*& get_type();
		int get_number();
		void copy_deliver(const delivery& to_copy);
		void copy_delivery(char* warehouse, char* deliver, char* name, int orders, float charge, char* type);
	protected:
		char* order_type;	//the type of order specified
		char* order_name;	//the name of the person who ordered
		int num_of_orders;	//the number of orders in each package
		float cost;		//the cost of the delivery in USD
};

//standard class prototype which is derived from the delivery class
class standard: public delivery 
{
	public:
		standard();
		virtual ~standard();
		standard(const standard& copy_order);		
		standard(char* warehouse, char* deliver, char* name, int distance, int orders, int time, float charge, char* type);
		//copy constructor for the standard class
	protected:
		int deliver_time;	//the delivery time in minutes
		int travel_miles;	//the distance between
};

//the express class was going to be a seperate class from standard but I figured the express class
//has all the features of standard class plus a few more members
class express: public standard
{
	public:
		express();
		~express();
		express(const express& copy_order);
		express(char* warehouse, char* deliver, char* name, int distance, int orders, int time, float charge, char* type);
	private:
		//the traffic condition and fee determine the express class
		char* traffic_condition;
		//the fee 
		float fee;
};

//the drone class is derived from the delivery class since a drone is a type of delivery
class drone: public delivery
{
	public:
		drone();
		~drone();
		drone(const drone& copy_order);
		drone(char* warehouse, char* deliver, char* name, int orders, char* way, int mass, int length, int width, int height, float charge, char* type);
	private:
		char* direction;
		int weight;		//the object must weigh less than 25 pounds
		int* volume;		//the volume will feature an array of 3 integers
};
