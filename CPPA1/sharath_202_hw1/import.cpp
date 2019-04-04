//Sharath Menon CS202 Programming Assignment 1
#include "structures.h"
using namespace std;

//this file manages the importing into a linear and circular linked list
//this lll manager function takes in a cll manager as an argument to
//insert into both lists. this way efficiency is preserved.
int lll_manager::importing_lists(cll_manager& add_list)
{	//set up the miporting function ifstream
    	ifstream importing; 		//naming the input datatype importing
    	char temp[31];			//have an array to store the characters
	char * name;			//name of person who ordered
	char * warehouse;		//the departure address
	char * deliver;			//the destination adress
    	int distance;			//the distance in miles
    	int orders;			//the number of products in the order
	int time;			//the deliver time in minutes
	float charge;			//the cost of the delivery
	int mass;			//the mass of the delivery in pounds
	//the dimensions of the package or order
	int length;			
	int width;
    	int height;
	char* type;
	char* way;
	int order_number = 0;
	delivery* to_insert_lll = NULL;
	route* to_insert_cll = NULL;
    	//inst is short for institute
    	importing.open("orders.txt");	//have a seperate library
    	while (!importing.eof())
    	{
		++order_number;
		//importing the contents from the text file
        	importing.get(temp, 31, ';');
        	importing.ignore(30, ';');
        	name = new char[strlen(temp)+1];
        	strcpy(name, temp);
    	
        	importing.get(temp, 31, ';');
        	importing.ignore(30, ';');
        	warehouse = new char[strlen(temp)+1];
        	strcpy(warehouse, temp);
    
        	importing.get(temp, 31, ';');
        	importing.ignore(30, ';');
        	deliver = new char[strlen(temp)+1];
        	strcpy(deliver, temp);

        	importing >> distance;
        	importing.ignore(10, ';');
        	importing >> orders;
        	importing.ignore(10, ';');
        	importing >> time;
        	importing.ignore(10, ';');
                importing >> charge;
        	importing.ignore(10, ';');
		importing >> mass;
        	importing.ignore(10, ';');
		importing >> length;
        	importing.ignore(10, ';');
		importing >> width;
        	importing.ignore(10, ';');
		importing >> height;
        	importing.ignore(10, '\n');
		int volume = length*width*height;
		float speed = time / distance;
		int longitude = strcmp(warehouse, deliver);
		int latitude = strlen(warehouse) - strlen(deliver);
		way = new char[10];
		//if the volume and weight are small enough implement the drone service
		if (volume >= 2500 && mass <= 35)
		{
			type = new char[6];
			strcpy(type, "drone");		
			if (longitude >= 0 && latitude >= 0)
				strcpy(way, "northwest");
			if (longitude < 0 && latitude >= 0)
				strcpy(way, "northeast");
			if (longitude >= 0 && latitude < 0)
				strcpy(way, "southwest");
			else
				strcpy(way, "southeast");
			
			//to_insert_lll = new delivery;
			//to_insert_lll->copy_delivery(warehouse, deliver, name, orders, charge, type);
			to_insert_lll = new drone(warehouse, deliver, name, orders, way, mass, length, width, height, charge, type);
		}
		else if (speed <= 2.5)
		{
			type = new char[8];
			strcpy(type, "express");
			//to_insert_lll = new delivery;
			//to_insert_lll->copy_delivery(warehouse, deliver, name, orders, charge, type);
			to_insert_lll = new express(warehouse, deliver, name, distance, orders, time, charge, type);
		}
		//otherwise implement the standard delivery service
		else
		{
			type = new char[9];
			strcpy(type, "standard");
			//to_insert_lll = new delivery;
			//to_insert_lll->copy_delivery(warehouse, deliver, name, orders, charge, type);
			to_insert_lll = new standard(warehouse, deliver, name, distance, orders, time, charge, type);
		}
		//cll and lll functions to insert a node into the data structure
		insert_order(*to_insert_lll);
		to_insert_cll = new route; //(*to_insert_lll);
		to_insert_cll->copy_contents(*to_insert_lll);
		add_list.insert_node(*to_insert_cll, order_number);

		//delete all dynamically allocated memory to save memory
		delete [] name;
		delete [] warehouse;
		delete [] deliver;
		delete [] way;
		delete [] type;
		delete to_insert_lll;
		delete to_insert_cll;
	}
	return 0;
}
