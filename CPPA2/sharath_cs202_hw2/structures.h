//Sharath Menon CS202 Programming Assignment 2
#include "homework.h"
//using namespace std;

//this class manages the functions and data members dor the doubly linked list (dll) nodes and list

//the class for the dll node
class d_node
{
	public:
		d_node();
		~d_node();
		d_node(const d_node& copy_assignment);
		d_node*& get_next();
		d_node*& get_previous();
		void display_dnode();
		void set_next(d_node*& add_assignment);
		void set_previous(d_node*& add_assignment);
		void add_excersize(const homework* add_assignment);
	private:
		//a dll node has an assignment class implemented
		homework * assignment;
		//as well as a previous and next pointer
		d_node * d_previous;
		d_node * d_next;
};

//this class manages the functions for the doubly linbked list or dll
class dll_manager
{
	public:
		dll_manager();
		~dll_manager();
		void import_readings();
		void import_worksheets();
		void import_essays();
		//function to insert the node into the list based on the abstract base class homework
		void insert_dnode(const homework* add_assignment);
		void display_list();
	private:
		void display_list(d_node * head);
		void destroy_dll_list(d_node*& head);
		d_node * d_head;
		d_node * tail;
			
};
