//Sharath Menon CS202 Programming Assignment 2
#include "structures.h"
using namespace std;

int main()
{	//implement the dll list
	dll_manager Data_Manager;

	Data_Manager.import_readings();
	cout << "The reading assignments have been uploaded! \n";
	Data_Manager.import_worksheets();
	cout << "The worksheets have been uploaded \n";
	Data_Manager.import_essays();
	cout << "The Essays have been uploaded \n";
	Data_Manager.display_list();
	cout << "The list has been displayed. \n";
	//list of variables to be used when inserting functions
	char response;
	char again = 'Y';
	char text[50];
	char writer[30];
	char title[50];
	int percentage;
	int page;
	int word_count;
	int section;
	int question_num;
	homework * to_insert_dll = NULL;

	//introduce the material to the user
	cout << "Here is a list of all the assignments completed this year. \n";
	do
	{	//instructions for the user
		cout << "Would you like to insert a node? \n";
		cout << "Press R to insert a reading assignment \n"
		     << "Press W to insert a worksheet assignment \n"
		     << "Press E to insert an essay                 ";
		//have a do while loop in case the user enters an incorrect value
		do {
			cout << "Press R to insert a reading assignment \n"
			     << "Press W to insert a worksheet assignment \n"
			     << "Press E to insert an essay                 ";
			cin >> response;
			cin.ignore(10, '\n');
			response = toupper(response);
		   } while(response != 'R' && response != 'W' && response != 'E');
		
		//have a selection
		if (response == 'R')
		{
			cout << "Enter the name of the textbook:    ";
			cin.get(text, 50, '\n');
			cin.ignore(30, '\n');
			cout << "What is the name of the author:    ";
			cin.get(writer, 30, '\n');
			cin.ignore(30, '\n');
			cout << "What chapter of the book:          ";
			cin >> section;
			cin.ignore(10, '\n');
			cout << "How many pages to be read:         ";
			cin >> page;
			cin.ignore(10, '\n');
			//the do while loop is for incase the user enters an invalid answer for score
			do {
				cout << "How much percentage of the section was read? Please enter a score between 0 and 100   ";
				cin >> percentage;
				cin.ignore(10, '\n');
			   } while(percentage < 0 || percentage > 100);
			//make a reasings class and insert the assignment into the dll
			to_insert_dll = new readings(text, writer, section, page, percentage);
			Data_Manager.insert_dnode(to_insert_dll);
			//delete the dll to prevent memory leaks
			delete to_insert_dll;			
		}
		//if the response is a w for worksheets
		if (response == 'W')
		{	//have the user enter in all the variables
			cout << "Enter the topic of the worksheet:           ";
			cin.get(title, 50, '\n');
			cin.ignore(30, '\n');
			cout << "Enter how many questions in the worksheet:  ";
			cin >> question_num;
			cin.ignore(10, '\n');
			do {
				cout << "Enter the score. Please enter a value between 0 and 100:     ";
				cin >> percentage;
				cin.ignore(10, '\n');
			   }while(percentage < 0 || percentage > 100);
			//use binding to pass set a base pointer to a derived class
			to_insert_dll = new worksheets(title, question_num, percentage);
			Data_Manager.insert_dnode(to_insert_dll);
			//to prevent memory leaks delete the data structure
			delete to_insert_dll;
		}
		//if the response is e for essays
		if (response == 'E')
		{	//have the user input the required variables
			cout << "Enter the title of the essay:           ";
			cin.get(title, 50, '\n');
			cin.ignore(30, '\n');
			cout << "How many pages does this essay have:    ";
			cin >> page;
			cin.ignore(10, '\n');
			cout << "How many words does this essay have:    ";
			cin >> word_count;
			cin.ignore(10, '\n');
			do {
				cout << "What score did you get on this essay? Please enter a value between 0 and 100:     ";
				cin >> percentage;
				cin.ignore(10, '\n');	
			} while(percentage < 0 || percentage > 100);
			//insert the variables into an essay class to insert into the data structure
			to_insert_dll = new reports(title, page, word_count, percentage);
			Data_Manager.insert_dnode(to_insert_dll);
			delete to_insert_dll;
		}
		cout << "Do you want to insert another node? Press Y for Yes, N for No   ";
		cin >> again;
		cin.ignore(10, '\n');
		again = toupper(again);
	} while (again != 'N');
	//the do while loop is for the user to enter in another entry
	//display the list
	cout << "Here is the new list: \n";
	Data_Manager.display_list();
	return 0;
}
