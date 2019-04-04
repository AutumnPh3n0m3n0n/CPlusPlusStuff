//Sharath Menon Programming Assignment 1
#include "structures.h"
using namespace std;
//this class manages the graph verticies and data structure
//this graph is implemented in a way where traversal can be 
//done back and forth

//default constructor for the graph vertex class
graph_vertex::graph_vertex()
{
	street = NULL;
	adjacent = NULL;
	backtrack = NULL;
}

//default destructor for the graph vertex class
graph_vertex::~graph_vertex()
{
	//if (street)
	delete [] street;
	adjacent = NULL;
	backtrack = NULL;
}

void graph_vertex::set_street(char* add_street)
{
	street = new char[strlen(add_street)+1];
	strcpy(street, add_street);
}

void graph_vertex::set_front(graph_vertex*& add_front)
{
	adjacent = add_front;
}

void graph_vertex::set_back(graph_vertex*& add_back)
{
	backtrack = add_back;
}

graph_vertex*& graph_vertex::get_front()
{
	return adjacent;
}

graph_vertex*& graph_vertex::get_back()
{
	return backtrack;
}

void graph_vertex::set_back_null()
{
	backtrack = NULL;
}

void graph_vertex::display_vertex()
{
	cout << street << " LINK \t";
}

//the functions for the graph data structure class
graph_edges::graph_edges()
{
	start = NULL;
	finish = NULL;
}

graph_edges::~graph_edges()
{
	if (start)
		destroy_graph(start);
}

void graph_edges::destroy_graph(graph_vertex*& current)
{
	if (!current->get_front())
		delete current;
	else
	{
		//current->set_back_null();
		destroy_graph(current->get_front());
		delete current;
	}	
}

void graph_edges::insert_vertex(char* add_street)
{
	graph_vertex * to_insert = new graph_vertex;
	to_insert->set_street(add_street);
	if (!start)
	{
		start = to_insert;
		finish = start;
	}
	else
	{
		finish->set_front(to_insert);
		to_insert->set_back(finish);
		finish = to_insert;	
	}
}

//wrapper function to display the graph
void graph_edges::display_graph()
{
	display_graph(start);
}

//recursive function to display the graph using head as a node
void graph_edges::display_graph( graph_vertex*& current)
{	//if the node is the last node in the lll display it
	if (!current->get_front())
	{	
		current->display_vertex();
		cout < "\n\n";	
		//have a buffer space
	}
	//otherwise do the same and call 
	else
	{
		current->display_vertex();
		display_graph(current->get_front());
	}
}

//this function is to import contents from the textfile to the graph
int graph_edges::importing_graph()
{
    	ifstream upload; //uploading the roads for the graph data structure
    	upload.open("roadmap.txt");	//have a seperate library 
	char upload_street[30];
	char* name_street;
	while (!upload.eof())
	{
		upload.get(upload_street, 25, '\n');
		upload.ignore(20, '\n');
		name_street = new char[strlen(upload_street)+1];
		strcpy(name_street, upload_street);
		insert_vertex(name_street);
		delete [] name_street;
	}
}

