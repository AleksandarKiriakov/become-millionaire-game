#pragma once 
#include <iostream>
#include <vector>
using namespace std;
string getFileName(int difficulty);
vector<int> countQuestions(int difficulty, int category);
string* parseQuestion(string line);
string* getQuestion(int difficulty, int currentLine);
string* randomQuestion(int difficulty, int category);
int findQuestion(int identNumber);
void EditQuestion(string question, string answer1, string answer2, string answer3, string answer4, int rigthAnswer, int category, int identNumber);
int main();