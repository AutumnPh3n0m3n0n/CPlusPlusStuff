#include "character.h"

//functions and data members for the 23 node class
class node_23
{
	public:
		node_23();
		~node_23();
		int set_first(character* to_set);
		int set_second(character* to_set);
		node_23*& get_left();
		node_23*& get_middle();
		node_23*& get_right();
		bool is_full();
		int display_data();
	private:
		character * avatar_1;
		character * avatar_2;
		node_23 * left;
		node_23 * middle;
		node_23 * right;
};

//functions and data members for the 23 tree class
class tree_23
{
	public:
		tree_23();
		~tree_23();
		//wrapper function to insert a character object
		int insert_character(character* to_insert);
		int display_all();
	private:
	  	int insert_character(character* to_insert, node_23*& root);
		int display_all(node_23* root);
		int destroy_tree(node_23*& root);
		node_23 * root;
};
