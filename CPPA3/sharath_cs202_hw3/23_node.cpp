//Sharath Menon Programing Assignment 3
//this class manages the functions for the 23 node
#include "structures.h"
using namespace std;

//constructor for the 23 node class
node_23::node_23()
{
	avatar_1 = NULL;
	avatar_2 = NULL;
	left = NULL;
	middle = NULL;
	right = NULL;
}

//destructor for the 23 node class
node_23::~node_23()
{
	if (avatar_1)
	{
		delete avatar_1;
		avatar_1 = NULL;
	}
	if(avatar_2)
	{
		delete avatar_2;
		avatar_2 = NULL;
	}
	if (left)
	{
		delete left;
		left = NULL;
	}
	if (middle)
	{
		delete middle;
		middle = NULL;
	}
	if (right)
	{
		delete right;
		right = NULL;
	}
}

//since the n23 node data members are private these are
//getter functions used when traversing the tree
//function to go to the left
node_23*& node_23::get_left()
{
	return left;
}

//get to the middle
node_23*& node_23::get_middle()
{
	return middle;
}

//get to the right
node_23*& node_23::get_right()
{
	return right;
}

//use downcasting to determine what derived class the character class is
int node_23::set_first(character* to_insert)
{
  	if (typeid(*to_insert) == typeid(elves))
  	{
    		const elves * object = (elves*)to_insert;
    		avatar_1 = new elves(*object);
  	}
  	else if (typeid(*to_insert) == typeid(monks))
  	{
    		const monks * object = (monks*)to_insert;
    		avatar_1 = new monks(*object);
  	}
  	else if (typeid(*to_insert) == typeid(warriors))
  	{
		const warriors * object = (warriors*)to_insert;
    		avatar_1 = new warriors(*object);
  	}
	else if(typeid(*to_insert) == typeid(orcs))
	{
		const orcs * object = (orcs*)to_insert;
		avatar_1 = new orcs(*object);
	}
	return 1;
}

//use downcasting to determine what derived class the character class is
int node_23::set_second(character* to_insert)
{
  	if (typeid(*to_insert) == typeid(elves))
  	{
    		const elves * object = (elves*)to_insert;
    		avatar_2 = new elves(*object);
  	}
  	else if (typeid(*to_insert) == typeid(monks))
  	{
    		const monks * object = (monks*)to_insert;
    		avatar_2 = new monks(*object);
  	}
  	else if (typeid(*to_insert) == typeid(warriors))
  	{
		const warriors * object = (warriors*)to_insert;
    		avatar_2 = new warriors(*object);
  	}
	else if(typeid(*to_insert) == typeid(orcs))
	{
		const orcs * object = (orcs*)to_insert;
		avatar_2 = new orcs(*object);
	}
	return 1;
}

//a boolean function to check whether the 23 node is full
bool node_23::is_full()
{
	if (avatar_1 != NULL  && avatar_2 != NULL)
		return true;

	return false;
}

//function to display the data
int node_23::display_data()
{
	if (avatar_1)
		avatar_1->display_info();
	if (avatar_2)
		avatar_2->display_info();
	return 1;
}
