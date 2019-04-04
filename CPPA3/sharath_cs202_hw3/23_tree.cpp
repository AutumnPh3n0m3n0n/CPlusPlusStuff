//Sharath Menon CS202 Programming Assignment 3
//This file manages the functions for the 23 tree class
#include "structures.h"
using namespace std;

//default constructor for the 23 tree
tree_23::tree_23()
{
	root = NULL;
}

//wrapper destructor for the 23 tree
tree_23::~tree_23()
{
	if (root)
		destroy_tree(root);
}

//recursive function for tree destructor
int tree_23::destroy_tree(node_23*& root)
{
	if (!root)
		return 0;

	destroy_tree(root->get_left());
	destroy_tree(root->get_middle());
	destroy_tree(root->get_right());
	if (root)
	{
		delete root;
		root = NULL;
	}
	return 1;
}

//wrapper function for inserting a character object into the tree
int tree_23::insert_character(character* to_insert)
{
    	insert_character(to_insert, root);
    	return 1;
}

//recursive function to insert the character function into the tree
int tree_23::insert_character(character* to_insert, node_23*& root)
{
    	if (!root)
    	{
        	root = new node_23;
        	root->set_first(to_insert);
        	return 1;
    	}
	if (!root->is_full())
	{
		root->set_second(to_insert);
		return 1;	
	}
	if(!root->get_left())
	{
		insert_character(to_insert, root->get_left());
	}
	/*
    	else if (!root->get_middle())
    	{
  		insert_character(to_insert, root->get_middle());
    	}
	else if(!root->get_right())
	{
		insert_character(to_insert, root->get_right());
	}
	
	if (to_insert < root->avatar_1 && to_insert < root->avatar_2)
	insert_character(to_insert, root->get_left());

	insert_character(to_insert, root->get_right());
	*/
	return 1;	
}

//display function for the tree
int tree_23::display_all()
{
	display_all(root);
	return 1;
}

//traversing function to display the tree
int tree_23::display_all(node_23* root)
{
	if (!root)
		return 0;
	root->display_data();
	display_all(root->get_left());
	display_all(root->get_middle());
	display_all(root->get_right());

	return 1;
}
