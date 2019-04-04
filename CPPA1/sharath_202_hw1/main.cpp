//Sharath Menon CS202 Programming Assignment 1
//this is the main file of the program

//import the header files
#include "structures.h"
using namespace std;
int main()
{	//have the variables for inserting an order
	//these variables are for inserting into the data structure
	char get_name[36];
	char * type;
	char * get_start;
	char* get_finish;
	char again;
	char response;
	char choice;
	int orders_num;
	float get_cost;
	delivery * adding_order = NULL;
	route * adding_route = NULL;
	//implement the data structures
	lll_manager Data_Struct1;
	cll_manager Data_Struct2;
	graph_edges Data_Struct3;
	Data_Struct1.importing_lists(Data_Struct2);
	Data_Struct3.importing_graph();
	//greet the user
	cout << "Hello! Welcome to Sharath's Delivery Tracker. There are three types of deliveries: \n"
	     << "Standard, Express, and Drone. The Standard delivery method delivers the package in "
	     << "a normal time with no sales tax. The Express delivery can quickly delivery the package \n"
	     << "in a quick time with a tax included. The drone delivery can delivery light packages via \n"
	     << "in a straight line, with a tax also included. \n";
	//output the number of nodes in the data structure
	cout << "There are currently " << Data_Struct1.get_num_orders() << " in the system, \n";
	
	//ask the user if they want to display the graph
	cout << "Would you like to display the road map? Press Y for Yes:  \t";
	cin >> response;
	cin.ignore(10, '\n');
	if (response == 'Y' || response == 'y')
		Data_Struct3.display_graph();

	//ask the user if they want to display the list of orders
	cout << "Would you like to display all of the orders? Press Y for Yes:  \t";
	cin >> response;
	cin.ignore(10, '\n');
	if (response == 'Y' || response == 'y')
		Data_Struct1.display_lll_list();

	//ask the user if they want to display the tracking list
	cout << "Would you like to track the orders? Press Y for Yes:  \t";
	cin >> response;
	cin.ignore(10, '\n');
	if (response == 'Y' || response == 'y')
		Data_Struct2.display_cll_list();

	//this following function asks the user whtther they want to insert into the data structure
	//this is all in a do while loop in case the user wants to enter multiple orders
	cout << "Would you like to add an order? Press Y for Yes, N for No \t";
	cin >> response;
	cin.ignore(10, '\n');
	response = toupper(response);
	if (response != 'N')
	{
		do {
			cout << "Press S for Standard " << "\n " << "Press E for Express" << "\n" 
		     	     << "Press D for Drone" << "\n "<< "Select you method of delivery:  \t";
			cin >> choice;
			cin.ignore(10, '\n');
			choice = toupper(choice);

			do {
				cout << "Enter the number of orders for your package. Enter a number between 1 and 10:    \t";
				cin >> orders_num;
				cin.ignore(10, '\n');
				if (orders_num < 1 || orders_num > 10)
					cout << "Please enter in a valid number \n";
			   } while (orders_num < 1 || orders_num > 10);
	
			if (choice == 'D')
			{
				type = new char[6];
				strcpy(type, "drone");
				get_cost = orders_num * 12.50;
			}
			else if (choice == 'E')
			{
				type = new char[8];
				strcpy(type, "express");
				get_cost = orders_num * 10.50;
			}
			//to be safe make this an else condition
			else
			{
				type = new char[9];
				strcpy(type, "standard");
				get_cost = orders_num * 8.50;
			}
			//the do while loop is for the condition

			//ask the user to input their name
			cout << "What is your name?  \t";
			cin.get(get_name, 36, '\n');
			cin.ignore(50, '\n');

			//obtain the starting address and destination address
			//get start is the warehouse address
			get_start = new char[16];
			strcpy(get_start, "Karla Boulevard");
			//get finish is the delivery address
			get_finish = new char[16];
			strcpy(get_finish, "Portland Street");
			//static binding is used to pass in a derived class as a base blass
			//since this program does not have any abstract base classes
			//dynamic binding cannot be achieved
			adding_order = new delivery(get_start, get_finish, get_name, orders_num, get_cost, type);
			Data_Struct1.insert_order(*adding_order);
			adding_route = new route;
			adding_route->copy_contents(*adding_order);
			Data_Struct2.insert_node(*adding_route, Data_Struct1.get_num_orders()); 
	
			//delete all dynamically allocated memory to prevent memory leaks
			delete [] type;
			delete [] get_start;
			delete [] get_finish;
			delete adding_order;
			delete adding_route;

			//asl the user if they want to insert another order
			cout << "Would you like to insert another order? Press Y for Yes   ";
			cin >> again;
			cin.ignore(10, '\n');
		}while (again == 'Y' || again == 'y');
	
		//ask the user if they want to display the list again
		cout << "Would you like the orders again? Press Y for Yes    ";
		if (response == 'y' || response == 'Y')
			Data_Struct1.display_lll_list();
	}
	return 0;
}
