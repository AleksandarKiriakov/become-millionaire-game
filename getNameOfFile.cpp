#include <string>
#include <iostream>
#include <sstream>
#define FILE_NAME "questions"
#define FILE_EXTENSION ".txt"
string getFileName(int difficulty)
{
	stringstream sstm;
	sstm << FILE_NAME << difficulty << FILE_EXTENSION;
	return sstm.str();
}