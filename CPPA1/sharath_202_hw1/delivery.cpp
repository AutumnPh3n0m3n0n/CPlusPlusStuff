//Sharath Menon CS202 Programming Assignment 1
#include "delivery.h"
using namespace std;

//default constructor setting all variables to their zero value
//since the standard class does not have any dynamic memory a destructor is not needed
standard::standard():delivery()
{
	deliver_time = 0;
	travel_miles = 0;
}

standard::~standard()
{
	//nothing goes in the destructor since there is no dynamic memory for this class
}

standard::standard(char* warehouse, char* deliver, char* name, int distance, int orders, int time, float charge, char* type):delivery(warehouse, deliver, name, orders, charge, type)
{
	deliver_time = time;
	travel_miles = distance;
}

//a copy constructor is needed since both standards child and parent classes have dynamic memory
standard::standard(const standard& copy_order):delivery(copy_order)
{
	deliver_time = copy_order.deliver_time;
	travel_miles = copy_order.travel_miles;
}

//default constructor for the exrpess class
express::express():standard()
{
	traffic_condition = NULL;
	fee = 0.00;
}

//destructor for the express class
express::~express()
{
	//if (traffic_condition)
	delete [] traffic_condition;
}

//copy consrtuctor for the express class
express::express(const express& copy_order):standard(copy_order)
{
	traffic_condition = new char[strlen(copy_order.traffic_condition)+1];
	strcpy(traffic_condition, copy_order.traffic_condition);
	fee = copy_order.fee;
}

//have conditionald to set the variables for the extended constructor for the express class
express::express(char* warehouse, char* deliver, char* name, int distance, int orders, int time, float charge, char* type):standard(warehouse, deliver, name, distance, orders, time, charge, type)
{
	if (time <= 15)
	{
		traffic_condition = new char[5];
		strcpy(traffic_condition, "good");
		fee = cost * 0.25;
	}
	else if (time > 15 && time <= 30)
	{
		traffic_condition = new char[9];
		strcpy(traffic_condition, "moderate");
		fee = cost* 0.2;
	}
	else if (time > 30)
	{
		traffic_condition = new char[5];
		strcpy(traffic_condition, "slow");
		fee = cost * 0.1;
	}
	//to be safe have an extra 
	else
	{
		traffic_condition = new char[8];
		strcpy(traffic_condition, "unknown");
		fee = cost * 0.2;
	}
	delete [] traffic_condition;
}

//the default constructore for the drone class sets all of its data members to its zero valua
drone::drone():delivery()
{
	direction = NULL;
	weight = 0.0;
	volume = new int[3];
	volume[0] = 0;
	volume[1] = 0;
	volume[2] = 0;
}

//drone destructor will delete all dynamically allocated memory
drone::~drone()
{
	//if (direction)
	delete [] direction;
	//if (volume)
	delete [] volume;
}

drone::drone(const drone& copy_order):delivery(copy_order)
{
	direction = new char[strlen(copy_order.direction)+1];
	strcpy(direction, copy_order.direction);
	weight = copy_order.weight;
	volume = new int[3];
	volume[0] = copy_order.volume[0];
	volume[1] = copy_order.volume[1];
	volume[2] = copy_order.volume[2];
}

drone::drone(char* warehouse, char* deliver, char* name, int orders, char* way, int mass, int length, int width, int height, float charge, char* type):delivery(warehouse, deliver, name, orders, charge, type)
{
	direction = new char[strlen(way)+1];
	strcpy(direction, way);
	weight = mass;
	volume = new int[3];
	volume[0] = length;
	volume[1] = width;
	volume[2] = height;
}
