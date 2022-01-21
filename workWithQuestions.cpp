/**
*
* Solution to course project #5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Aleksandar Kiriakov
* @idnumber 6MI0600087
* @compiler VC
*
* <operations with questions>
*
*/

#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "workWithQuestions.h"
#include "Border.h"
#define QUESTION_ATTRIBUTES 8
#define NO_CATEGORY 6
#define FILE_NAME "questions"
#define FILE_EXTENSION ".txt"
#define QUESTION_DELIMITER '|'
string getFileName(int difficulty)
{
	stringstream sstm;
	sstm << FILE_NAME << difficulty << FILE_EXTENSION;
	return sstm.str();
}
vector<int> countQuestions(int difficulty, int category)
{
	string fileName = getFileName(difficulty);
	ifstream file;
	vector<int> currentLine;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Error opening file";
		return currentLine;
	}
	int numberOfQuestions = 0;
	int line = 1;
	string buffer = {};
	while (getline(file, buffer))
	{
		int categoryFromBuffer = 0;
		while (buffer[categoryFromBuffer] != '|')
		{
			categoryFromBuffer++;
		}
		categoryFromBuffer += 1;
		int currentCategory = buffer[categoryFromBuffer] - '0';
		if (category == currentCategory || category == NO_CATEGORY)
		{

			currentLine.push_back(line);
		}
		line++;
	}
	file.close();
	return currentLine;
}
string* parseQuestion(string line)
{
	string* result = new string[QUESTION_ATTRIBUTES];
	int parametersCounter = 0;
	int bufferCounter = 0;
	while (line[bufferCounter] != '\0')
	{
		if (line[bufferCounter] == QUESTION_DELIMITER)
		{
			parametersCounter++;
			bufferCounter++;
			continue;
		}
		result[parametersCounter] += line[bufferCounter];
		bufferCounter++;
	}
	return result;
}
string* getQuestion(int difficulty, int currentLine)
{
	string fileName = getFileName(difficulty);
	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Error opening file";
		return 0;
	}
	string* question = {};
	string buffer = {};
	int counter = 0;
	while (getline(file, buffer))
	{
		counter++;
		if (currentLine == counter)
		{
			question = parseQuestion(buffer);
			break;
		}
	}
	file.close();
	return question;
}
string* randomQuestion(int difficulty, int category)
{
	vector<int> currentLine = countQuestions(difficulty, category);
	int sizeOfCurrentLine = currentLine.size();
	int randomQuestion = rand() % sizeOfCurrentLine + 1;
	string* question = {};
	int line = (currentLine[randomQuestion - 1]);
	question = getQuestion(difficulty, line);
	return question;
}
int findQuestion(int identNumber)
{
	int fileNumber = -1;
	for (size_t i = 1; i <= 10; i++)
	{
		string fileName = getFileName(i);
		ifstream file;
		file.open(fileName);
		if (!file.is_open())
		{
			cout << "Error opening file";
			return 0;
		}
		string* question = {};
		int currentLine = 0;
		string buffer = {};
		while (getline(file, buffer))
		{
			if ((buffer[0] - '0') == identNumber)
			{
				fileNumber = i;
				return fileNumber;
			}
		}
		file.close();
	}
	return fileNumber;
}
void EditQuestion(string question, string answer1, string answer2, string answer3, string answer4, int rigthAnswer, int category, int identNumber)
{
	string fileName = getFileName(findQuestion(identNumber));
	ifstream file;
	vector<string> allQuestionsFromFile;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Error opening file";
		return;
	}
	string buffer = {};
	string Category;
	Category = to_string(category);
	string id;
	id = to_string(identNumber);
	while (getline(file, buffer))
	{
		bool checkForCurrectIdent = false;
		int i = 0;
		while (buffer[i] != '|')
		{
			if (buffer[i] == id[i])
			{
				checkForCurrectIdent = true;
				i++;
				continue;
			}
			checkForCurrectIdent = false;
			i++;
		}
		if (checkForCurrectIdent)
		{
			string rightanswer;
			rightanswer += rigthAnswer;
			buffer = id + "|" + Category + "|" + question + "|" + answer1 + "|" + answer2 + "|" + answer3 + "|" + answer4 + "|" + rightanswer;
		}
		allQuestionsFromFile.push_back(buffer);
	}
	file.close();
	ofstream file1;
	file1.open(fileName);
	for (size_t i = 0; i < allQuestionsFromFile.size(); i++)
	{
		file1 << allQuestionsFromFile[i] << "\n";
	}
	file1.close();
}
