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
* <adding question to file>
*
*/

#include "workWithFileIdentNumber.h"
#include "workWithQuestions.h"
#include <fstream>
#include <iostream>
#include "addingQuestionToFile.h"
#define QUESTION_DELIMITER '|'
void OutputQuestionToFile(string question, string answer1, string answer2, string answer3, string answer4, char rigthAnswer, int category, int difficulty)
{
	int nextIdent = getNextIdent();
	string fileName = getFileName(difficulty);
	ofstream file;
	file.open(fileName, ostream::app);
	file << nextIdent << QUESTION_DELIMITER << category << QUESTION_DELIMITER << question << QUESTION_DELIMITER << answer1 << QUESTION_DELIMITER << answer2
		<< QUESTION_DELIMITER << answer3 << QUESTION_DELIMITER << answer4 << QUESTION_DELIMITER << rigthAnswer << "\n";
	file.close();
	writeIndent(nextIdent);
}