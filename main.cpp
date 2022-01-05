#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include<windows.h>
#define MAX_BUFFER_SIZE 2048
#define MAX_STRING_SIZE 300
#define QUESTION_ATTRIBUTES 7
#define NO_CATEGORY 6
#define FILE_NAME "questions"
#define FILE_EXTENSION ".txt"
#define QUESTION_DELIMITER '|'

	using namespace std;

	string getFileName(int difficulty) {
		stringstream sstm;
		sstm << FILE_NAME << difficulty << FILE_EXTENSION;
		return sstm.str();
	}

	char ** parseQuestion(char * line) {
		char ** result = new char*[QUESTION_ATTRIBUTES];
		for (int i = 0; i < QUESTION_ATTRIBUTES; i++) {
			result[i] = new char[MAX_STRING_SIZE];
		}

		int bufferCounter = 0;
		int characterCounter = 0;
		int parametersCounter = 0;
		while (line[bufferCounter] != '\0') {
			if (line[bufferCounter] == QUESTION_DELIMITER) {
				result[parametersCounter][characterCounter] = '\0';
				parametersCounter++;
				bufferCounter++;
				characterCounter = 0;
				continue;
			}
			result[parametersCounter][characterCounter] = line[bufferCounter];
			characterCounter++;
			bufferCounter++;
		}
		return result;
	}

	vector<int> countQuestions(int difficulty, int category) {
		string fileName = getFileName(difficulty);
		vector<int> questionLines;

		ifstream file;
		file.open(fileName);
		if (!file.is_open()) {
			cout << "Error opening file";
			return questionLines;
		}

		int numberOfQuestions = 0;
		int line = 1;
		char buffer[MAX_BUFFER_SIZE];
		while (file.getline(buffer, sizeof(buffer))) {
			int currentCategory = buffer[0] - '0';
			if (category == currentCategory || category == NO_CATEGORY) {
				questionLines.push_back(line);
			}
			line++;
		}
		file.close();
		return questionLines;
	}

	char** getQuestion(int difficulty, int line) {
		string fileName = getFileName(difficulty);

		ifstream file;
		file.open(fileName);

		if (!file.is_open()) {
			cout << "Error opening file";
			return 0;
		}
		char** question = {};
		int currentLine = 0;
		char buffer[MAX_BUFFER_SIZE];
		while (file.getline(buffer, sizeof(buffer))) {
			currentLine++;
			if (currentLine == line) {
				question = parseQuestion(buffer);
				break;
			}

		}
		file.close();
		return question;
	}
	void printDownFrame()
	{
		cout << setw(60) << setfill('=') << "" << endl;
	}
	void printUpperFrame() {
		cout << setw(30) << setfill('=') << "Get Rich" << setw(30) << setfill('=') << "" << endl;
	}
	void printMainMenu() {
		printUpperFrame();
		cout << setw(30) << setfill(' ') << "1.New game" << endl;
		cout << setw(37) << setfill(' ') << "2.Writing new question" << endl;
		cout << setw(39) << setfill(' ') << "3.Change existing question" << endl;
		cout << setw(28) << setfill(' ') << "4.Exit" << endl;
		printDownFrame();
	}
	void printNewGameMenu(int choice) {
		printDownFrame();
		cout << setw(34) << setfill(' ') << "Choose category" << endl;
		cout << setw(34) << setfill(' ') << "1. Politics" << endl;
		cout << setw(33) << setfill(' ') << "2. History" << endl;
		cout << setw(35) << setfill(' ') << "3. Geography" << endl;
		cout << setw(36) << setfill(' ') << "4. Literature" << endl;
		cout << setw(33) << setfill(' ') << "5. Physics" << endl << endl;
		cout << setw(40) << setfill(' ') << "6. All categories" << endl << endl;
		cout << setw(37) << setfill(' ') << "Write you choice: ";
		cin >> choice;
		printDownFrame();
		system("PAUSE");
		while (1 > choice || choice > 6)
		{
			cout << "Wrong number try new one: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			system("CLS");
		}
		else if (choice == 2)
		{
			system("CLS");
		}
		else if (choice == 3)
		{
			system("CLS");
		}
		else if (choice == 4)
		{
			system("CLS");
		}
		else if (choice == 5)
		{
			system("CLS");
		}
		else if (choice == 6)
		{
			system("CLS");
		}
	}
	bool CheckForCurrectInputInMenu(int b) {
		if (b == 1 || b==2 || b==3|| b==4)
		{
			return true;
		}
		return false;
	}

	int main()
	{	
		while (true)
		{
			int choice;
			printMainMenu();
			cin >> choice;
			while (!CheckForCurrectInputInMenu(choice)) {
				cin >> choice;
			}
			system("CLS");
			if (choice == 1){
				printNewGameMenu(choice);
			}
			else if (choice == 2)
			{
				printUpperFrame();
				string Question,answerA, answerB, answerC, answerD;
				cout << "Insert Question:" << endl;
				cin >> Question;
				printDownFrame();
				system("PAUSE");
				system("CLS");
				printUpperFrame();
				cout << "Insert answers:"<<endl;
				cout << "A) ";
				cin >> answerA;
				cout << "B) ";
				cin >> answerB;
				cout << "C) ";
				cin >> answerC;
				cout << "D) ";
				cin >> answerD;
					printDownFrame();
					system("PAUSE");
					system("CLS");
					printUpperFrame();
					char Answer;
					cout << "Choose right answer (A,B,C,D): ";
						cin >> Answer;
						while (Answer!='A'&& Answer != 'B'&& Answer != 'C'&& Answer != 'D'){
							cout << "Not valid letter write new one:";
							cin >> Answer;
						}
					printDownFrame();
					system("PAUSE");
					system("CLS");
					printUpperFrame();
					int Difficult;
					string Category;
					cout << "How difficult the question is (1-10): ";
					cin >> Difficult;
					while (Difficult<1 || Difficult>10)
					{
						cout << "Wrong number try new one: ";
						cin >> Difficult;
					}
					cout << endl << "which category is the question: ";
					cin >> Category;
					while (Category!="Politics"&& Category != "History"&& Category != "Geography"&& Category != "Literature"&& Category != "Physics")
					{
						cout<< "Wrong category try new one: ";
						cin >> Category;
					}
					printDownFrame();
					system("PAUSE");
					system("CLS");
			}
			else if (choice == 3)
			{
				printUpperFrame();
				int IdOfQuestion;
				cout << "Enter question ID: ";
				cin >> IdOfQuestion;
				while (!IdOfQuestion)
				{
					cout << "Enter new valid number: ";
					cin >> IdOfQuestion;
				}
				printDownFrame();
				system("PAUSE");
				system("CLS");
			}
			else if (choice == 4)
			{
				return 0;
			}
		}
	}