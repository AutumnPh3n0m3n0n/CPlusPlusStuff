//Sharath Menon CS202 Programming Assignment 2
#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <time.h>
#include <stdlib.h>

//i put the circularly linked list node at the first file since the
//worksheet class is using this. the worksheet class serves at a
//circularly linked list.

class c_node
{
	public:
		c_node();
		~c_node();
		c_node(const c_node& copy_question);
		void set_question(char* add_question, char the_answer);
		c_node*& get_next();
		void set_next(c_node*& set_question);
		void display_node();
		void set_next_null();
	private:
		//a characgter array for the question
		char * question;
		//a boolean variable if the question is answered correctly
		bool answered_correctly;
		//a next pointer for the cll node
		c_node * c_next;
};

//class that manages the homework
class homework
{
	public:
		homework();
		virtual ~homework();
		virtual void display_homework() = 0;
		virtual void copy_contents(const homework& to_copy) = 0;
		//this function will determine the score and if the homework
		//assignment is completed or not
		void set_score_completed(int percentage);
		int get_score();
	protected:
		bool if_completed;
		int score;
};

//class that manages the readings which are derived from the homework
class readings: public homework
{
	public:
		readings();
		~readings();
		readings(char* text, char* writer, int section, int page, int percentage);
		readings(const readings& copy_assignment);
		void copy_contents(const homework& to_copy);
		void display_homework();
		void copy_contents(const readings& to_copy);
	protected:
		char * textbook;
		char * author;
		int chapter;
		int pages;
};

class worksheets: public homework
{
	public:
		worksheets();
		~worksheets();
		worksheets(char* idea, int question_num, int points);
		worksheets(const worksheets& copy_assignment);
		void insert_question(char* add_question, char the_answer);
		void copy_contents(const homework& to_copy);
		void copy_contents(const worksheets& to_copy);
		void display_homework();
	protected:
		void display_cll_list(c_node* head);
		void destroy_cll(c_node*& head);
		char * topic;
		int num_of_questions;
		c_node * c_head;
		c_node * rear;
};

class reports: public homework
{
	public:
		reports();
		~reports();
		reports(const reports& copy_assignment);
		reports(char* idea, int page, int word_count, int score);
		void copy_contents(const homework& to_copy);
		void copy_contents(const reports& to_copy);
		void display_homework();
	protected:
		char * title;
		int pages;
		int words;
		
};
