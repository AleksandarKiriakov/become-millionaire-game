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
* <new game starter>
*
*/

#include "newGame.h"
#include "Border.h"
#include "workWithQuestions.h"
#include "joker.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#define QUESTION_ATTRIBUTES 8
using namespace std;
void printQuestion(string* question)
{
	for (size_t i = 2; i < QUESTION_ATTRIBUTES - 1; i++)
	{
		cout << question[i] << endl;
	}
}
void choosingGame(int& counter, int& choice, string& UserChoice) {
	cout << "\x1B[2J\x1B[H";
	bool x = true;
	bool y = true;
	bool z = true;
	while (true)
	{
		printUpperFrame();
		cout << "Question Number: " << counter << endl;
		string* question = randomQuestion(counter, choice);
		printQuestion(question);
		if (!x && !y && !z)
		{

		}
		else
		{
			cout << "You can use joker:";
		}
		if (x)
		{
			cout << " ";
			cout << "|X - 50 / 50|";
		}
		if (y)
		{
			cout << " ";
			cout << "|Y - help from audience|";
		}
		if (z)
		{
			cout << " ";
			cout << "|Z - call friend|";
		}
		cout << endl;
		cout << endl << "Use only small letters! Only jokers with big letters!" << endl;
		printDownFrame();
		cin >> UserChoice;
		cout << endl;
		if ((x == true) && UserChoice[0] == 'X')
		{
			cout << "\x1B[2J\x1B[H";
			int elim1 = 0;
			int elim2 = 0;
			string rightAnswer = question[QUESTION_ATTRIBUTES - 1];
			useFiftyFifty(rightAnswer, elim1, elim2);
			printUpperFrame();
			for (size_t i = 2; i < QUESTION_ATTRIBUTES - 1; i++)
			{
				if (i == elim1 || i == elim2)
				{
					continue;
				}
				cout << question[i] << endl;
			}
			printDownFrame();
			cout << "Your choice: ";
			cin >> UserChoice;
			x = false;
		}
		if ((y == true) && UserChoice[0] == 'Y')
		{
			cout << "\x1B[2J\x1B[H";
			printUpperFrame();
			int first = 0, second = 0, third = 0, fourth = 0;
			string rightAnswer = question[QUESTION_ATTRIBUTES - 1];
			useAudience(rightAnswer, counter, first, second, third, fourth);
			printQuestion(question);
			cout << "Audience oppinion: " << "a)" << first << " b)" << second << " c)" << third << " d)" << fourth << endl;
			printDownFrame();
			cout << "Your choice: ";
			cin >> UserChoice;
			y = false;
		}
		if ((z == true) && UserChoice[0] == 'Z')
		{
			cout << "\x1B[2J\x1B[H";
			printUpperFrame();
			int first, second, third, fourth;
			useAudience(question[QUESTION_ATTRIBUTES - 1], counter, first, second, third, fourth);
			printQuestion(question);
			printDownFrame();
			int answerFromFriend;
			answerFromFriend = CallFriend(question[QUESTION_ATTRIBUTES - 1], counter);
			if (answerFromFriend == 1)
			{
				cout << "Hello i think the right answer is a)" << endl;
			}
			else if (answerFromFriend == 2)
			{
				cout << "Hello i think the right answer is b)" << endl;
			}
			else if (answerFromFriend == 3)
			{
				cout << "Hello i think the right answer is c)" << endl;
			}
			else if (answerFromFriend == 4)
			{
				cout << "Hello i think the right answer is d)" << endl;
			}
			cout << endl << "Your choice: ";
			cin >> UserChoice;
			z = false;
		}
		if (UserChoice == question[QUESTION_ATTRIBUTES - 1])
		{
			cout << "\x1B[2J\x1B[H";
			printUpperFrame();
			cout << setw(33) << setfill(' ') << "Congrats you win: " << 100 * counter << "lv" << endl << endl;
			printDownFrame();
			cout << "Write any letter to continue: ";
			cin >> UserChoice;
			cout << "\x1B[2J\x1B[H";
			if (counter == 10)
			{
				printUpperFrame();
				cout << setw(37) << setfill(' ') << "Congrats you won! " << endl;
				printDownFrame();
				cout << "Write any letter to continue:  ";
				cin >> UserChoice;
				cout << "\x1B[2J\x1B[H";
				break;
			}
			counter++;
			continue;
		}
		else
		{
			cout << "\x1B[2J\x1B[H";
			printUpperFrame();
			cout << "Wrong answer try again!" << endl
				<< "Right answer to question number " << counter << " is: " << '"' << question[QUESTION_ATTRIBUTES - 1] << '"' << endl;
			cout << "Click any key to go to main menu..." << endl;
			printDownFrame();
			cout << "Write any letter to continue: ";
			cin >> UserChoice;
			cout << "\x1B[2J\x1B[H";
			break;
		}

	}
	return;
}