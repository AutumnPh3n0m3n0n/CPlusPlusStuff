//Sharath Menon CS202 Programming Assignment 1

//this file is names structures because this header file manages
//all the data structures and nodes
//this file has the prototypes for the lll structure and nodes
//the cll structure and nodes and the graph data structure
#include "delivery.h"
//using namespace std;

//this class is specifically for the circular linked list node
//this node has a route class track number and next pointer
class c_node
{
	public:
		c_node();
		~c_node();
		c_node(const c_node& copy_order);
		c_node*& get_next();
		void set_next(c_node*& to_next);
		void set_next_null();
		void set_info(const route& set_route, int order_number);
		void display_cnode();
	private:
		//the route class is not dynamic for inheritance purposes
		route pathway;
		//this number is to track the orders
		int track_number;
		//i called this pointer c_next to avoid confustion
		//with the linear linked list node l_next
		c_node * c_next;
};

//this class manages the circular linked list data structure
class cll_manager
{
	public:
		cll_manager();
		~cll_manager();
		void insert_node(const route& add_order, int order_number);
		void display_cll_list();
	private:
		//these functions are accessed through wrapper functions in the cll public domain
		void display_cll_list(c_node*& current);
		//this data member tells how many orders or nodes in the data structure there are
		int num_of_paths;
		void delete_all(c_node*& current);
		c_node * c_head;
		c_node * c_tail;
};


//this class manages all the information for the 
class l_node
{
	public:
		l_node();
		~l_node();
		l_node(const l_node& copy_order);
		l_node*& get_next();
		void display_lnode();
		//setter functions for setting the next pinter and the delivery information
		void set_next(l_node*& to_next);
		void set_info(const delivery& add_order);
	private:
		//the lll node has a delivery class in it as well as a node pointer
		delivery info;
		l_node * l_next;
};

//class for the linear linked list
class lll_manager
{
	public:
		lll_manager();
		~lll_manager();
		void insert_order(const delivery& add_order);
		void display_lll_list();
		//function to import orders to both the cll and lll lists
		//this function takes in an entire data structure as an argument
		//to preserve efficiency
		int importing_lists(cll_manager& add_list);
		//function to return the number of orders
		int get_num_orders();
	private:
		void display_lll_list(l_node*& current);
		int num_of_orders;
		void delete_all(l_node*& current);
		l_node * l_head;
		l_node * l_tail;
};

//class for the graph node or vertex
class graph_vertex
{
	public:
		graph_vertex();		//graph node constructor
		~graph_vertex();	//graph node destructor
		void set_street(char* add_street);
		void set_front(graph_vertex*& add_front);
		void set_back(graph_vertex*& add_back);
		graph_vertex*& get_front();
		graph_vertex*& get_back();
		void set_back_null();	//random function to set the previous pointer to null
		void display_vertex();
	private:
		char* street;		//this variable represents the streets
		graph_vertex* adjacent;	//this is named after the term adjacency list
		graph_vertex* backtrack;
};

//class for the graph data structure
class graph_edges
{
	public:
		graph_edges();
		~graph_edges();
		//function to import the graph	
		int importing_graph();
		//function to import the graph data structure
		void insert_vertex(char* add_street);
		void display_graph();
	private:
		//these functions are accessed through wrapper functions in the class public domain
		void destroy_graph(graph_vertex*& current);
		void display_graph(graph_vertex*& current);
		//pointers to represent the beginning and end ofthe graph
		graph_vertex * start;
		graph_vertex * finish;
};


