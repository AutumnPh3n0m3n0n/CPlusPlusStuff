//Sharath Menon Programming Assignment 2
#include "homework.h"
using namespace std;

//default constructor for homework
homework::homework()
{
	score = 0;
	if_completed = false;
}

homework::~homework()
{
	//technically nothing should go in here since there is no dynamic memory
	//the default destructor nust be included or the compiler will be upset
}

//function to set the completed parameters
void homework::set_score_completed(int percentage)
{
	score = percentage;
	if (score >= 65)
		if_completed = true;
	else
		if_completed = false;
}

//function to get the score
int homework::get_score()
{
	return score;
}


