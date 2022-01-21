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
* <program starter>
*
*/

#include "addingQuestionToFile.h"
#include "Border.h"
#include "newGame.h"
#include "workWithFileIdentNumber.h"
#include "workWithQuestions.h"
#include "joker.h"
#include <iostream>
#include <iomanip>
using namespace std;
	void printMainMenu()
	{
		printUpperFrame();
		cout << setw(30) << setfill(' ') << "1.New game" << endl;
		cout << setw(37) << setfill(' ') << "2.Writing new question" << endl;
		cout << setw(39) << setfill(' ') << "3.Change existing question" << endl;
		cout << setw(28) << setfill(' ') << "4.Exit" << endl;
		printDownFrame();
	}
	void printNewGameMenu()
	{
		printDownFrame();
		cout << setw(34) << setfill(' ') << "Choose category" << endl;
		cout << setw(34) << setfill(' ') << "1. Politics" << endl;
		cout << setw(33) << setfill(' ') << "2. History" << endl;
		cout << setw(35) << setfill(' ') << "3. Geography" << endl;
		cout << setw(36) << setfill(' ') << "4. Literature" << endl;
		cout << setw(33) << setfill(' ') << "5. Physics" << endl << endl;
		cout << setw(40) << setfill(' ') << "6. All categories" << endl << endl;
		printDownFrame();
		cout << "Write you choice: ";

	}
	bool CheckForCurrectInputInMenu(int b)
	{
		return b == 1 || b == 2 || b == 3 || b == 4;
	}
	void InsertQuestionFromUser(string& Question, string& answerA, string& answerB, string& answerC, string& answerD, char& rightAnswer, int& Category, int& Difficult)
	{
		string categoryString;
		cout << "How difficult the question is (1-10): ";
		cin >> Difficult;
		while (Difficult < 1 || Difficult> 10)
		{
			cout << "Wrong number try new one: ";
			cin >> Difficult;
		}
		cout << endl << "Which category is the question (Politics, History, Geography, Literature, Physics): ";
		cin >> categoryString;
		while (categoryString != "Politics" && categoryString != "History" && categoryString != "Geography" && categoryString != "Literature" && categoryString != "Physics" && categoryString != "All category")
		{
			cout << "Wrong category try new one: ";
			cin >> categoryString;
		}
		if (categoryString == "Politics")
		{
			Category = 1;
		}
		else if (categoryString == "History")
		{
			Category = 2;
		}
		else if (categoryString == "Geography")
		{
			Category = 3;
		}
		else if (categoryString == "Literature")
		{
			Category = 4;
		}
		else if (categoryString == "Physics")
		{
			Category = 5;
		}
		else if (categoryString == "All categories")
		{
			Category = 6;
		}
		printDownFrame();
		cout << "\x1B[2J\x1B[H";
		printUpperFrame();
		cout << "Insert Question:" << endl;
		cin >> Question;
		printDownFrame();
		cout << "\x1B[2J\x1B[H";
		printUpperFrame();
		cout << "Insert answers:" << endl;
		cout << "a) ";
		cin >> answerA;
		cout << "b) ";
		cin >> answerB;
		cout << "c) ";
		cin >> answerC;
		cout << "d) ";
		cin >> answerD;
		printDownFrame();
		cout << "\x1B[2J\x1B[H";
		printUpperFrame();
		cout << "Choose right answer (a,b,c,d): ";
		cin >> rightAnswer;
		while (rightAnswer != 'a' && rightAnswer != 'b' && rightAnswer != 'c' && rightAnswer != 'd')
		{
			cout << "Not valid letter write new one:";
			cin >> rightAnswer;
		}

		printDownFrame();
		cout << "\x1B[2J\x1B[H";
	}
	int main()
	{	
		while (true)
		{
			int choice=0;
			printMainMenu();
			cout << "Write you choice: ";
			cin >> choice;
			while (!CheckForCurrectInputInMenu(choice))
			{
				cin >> choice;
			}
			cout << "\x1B[2J\x1B[H";
			if (choice==1)
			{
				printNewGameMenu();
				cin >> choice;
				string UserChoice;
				int counter = 1;
				choosingGame(counter, choice, UserChoice);
			}
			else if (choice == 2)
			{
				int Difficult, Category;
				string Question, answerA, answerB, answerC, answerD;
				char rightAnswer;
				InsertQuestionFromUser(Question, answerA, answerB, answerC, answerD, rightAnswer, Category, Difficult);
				OutputQuestionToFile(Question, answerA, answerB, answerC, answerD, rightAnswer, Category, Difficult);
			}
			else if (choice == 3)
			{
				printUpperFrame();
				int IdOfQuestion;
				cout << "Enter question ID: ";
				cin >> IdOfQuestion;
				while (IdOfQuestion >= getNextIdent())
				{
					cout << "Enter new valid number: ";
					cin >> IdOfQuestion;
				}
				printDownFrame();
				cout << "\x1B[2J\x1B[H";
				while (findQuestion(IdOfQuestion)==-1)
				{
					cout << "ID of question isn't found. Please insert new: ";
					cin >> IdOfQuestion;
				}
				int Difficult, Category;
				string Question, answerA, answerB, answerC, answerD;
				char rightAnswer;
				InsertQuestionFromUser(Question, answerA, answerB, answerC, answerD, rightAnswer, Category, Difficult);
				EditQuestion(Question, answerA, answerB, answerC, answerD, rightAnswer, Category, Difficult);
			}
			else if (choice == 4)
			{
				return 0;
			}
		}
	}