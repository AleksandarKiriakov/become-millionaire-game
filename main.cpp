#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#define QUESTION_ATTRIBUTES 8
#define NO_CATEGORY 6
#define FILE_NAME "questions"
#define FILE_EXTENSION ".txt"
#define QUESTION_DELIMITER '|'

using namespace std;
	int generateWrongAnswer(int rightAnswer) {
	int answer;
	answer = rand() % 4 + 1;
	while (answer == rightAnswer && answer == 0){
		answer = rand() % 4 + 1;
	}
	return answer;
}
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
		int line = (currentLine[randomQuestion-1]);
		question = getQuestion(difficulty, line);
		return question;
	}
	//joker.h
	void useFiftyFifty(string rightAnswer, int& eliminated1, int& eliminated2)
	{
		int rightAnswerCastedToInt=0;
		if (rightAnswer[0] == 'a')
		{
			rightAnswerCastedToInt = 3;
		}
		else if (rightAnswer[0] == 'b')
		{
			rightAnswerCastedToInt = 4;
		}
		else if (rightAnswer[0] == 'c')
		{
			rightAnswerCastedToInt = 5;
		}
		else if (rightAnswer[0] == 'd')
		{
			rightAnswerCastedToInt = 6;
		}
		while (eliminated1 == eliminated2 || eliminated1 == rightAnswerCastedToInt || eliminated2 == rightAnswerCastedToInt)
		{
			eliminated1 = (rand() % 4) + 3;
			eliminated2 = (rand() % 4) + 3;
		}
	}
	void getRandomProcentageToAnswersWhenIsWrong(int rightAnswer, int& first, int& second, int& third, int& fourth)
	{
		int answer;
		answer = generateWrongAnswer(rightAnswer);
		if (answer == 1 )
		{
			while (first == 0 && second == 0 && third == 0 && fourth == 0)
			{
				first = rand() % 50 + (rand() % 50 + 1);
				second = rand() % (100 - first);
				third = rand() % (100 - first - second);
				fourth = rand() % (100 - first - second - third);
			}
			if (first + second + third + fourth < 100)
			{
				first += (100 - second - third - fourth- first);
			}
			return;
		}
		else if (answer == 2)
		{
			while (first == 0 && second == 0 && third == 0 && fourth == 0)
			{
				second = rand() % 50 + (rand() % 50 + 1);
				first = rand() % (100 - second);
				third = rand() % (100 - first - second);
				fourth = rand() % (100 - first - second - third);
			}
			if (first + second + third + fourth < 100)
			{
				second += (100 - first - third - fourth- second);
			}
			return;
		}
		else if (answer == 3)
		{
			while (first == 0 && second == 0 && third == 0 && fourth == 0)
			{
				third = rand() % 50 + (rand() % 50 + 1);
				first = rand() % (100 - third);
				second = rand() % (100 - first-third);
				fourth = rand() % (100 - first - second - third);
			}
			if (first + second + third + fourth < 100)
			{
				third += (100 - first - second - fourth- third);
			}
			return;
		}
		else if (answer == 4) {
			while (first == 0 && second == 0 && third == 0 && fourth == 0)
			{
				fourth = rand() % 50 + (rand() % 50 + 1);
				first = rand() % (100 - fourth);
				second = rand() % (100 - fourth - first);
				third = rand() % (100 - fourth - first - third);
			}
			if (first + second + third + fourth < 100)
			{
				fourth += (100 - first - second - third- fourth);
			}
			return;
		}
	}
	void getRandomProcentageToAnswersWhenIsRight(int rightAnswer, int& first, int& second, int& third, int& fourth)
	{
		if (rightAnswer == 1)
		{
			while (first == 0 || second == 0 || third == 0 || fourth == 0 || (first < second + third)) 
			{
				first = rand() % 50 + (rand() % 50 + 1);
				second = rand() % (100 - first);
				third = rand() % (100 - first - second);
				fourth = rand() % (100 - first - second - third);
			}
			if (first + second + third + fourth < 100)
			{
				first += (100 - second - third - fourth - first);
			}
			return;
		}
		else if (rightAnswer == 2)
		{
			while (first == 0 || second == 0 || third == 0 || fourth == 0 || (second < first + third))
			{
				second = rand() % 50 + (rand() % 50 + 1);
				first = rand() % (100 - second);
				third = rand() % (100 - first - second);
				fourth = rand() % (100 - first - second - third);
			}
			if (first + second + third + fourth < 100)
			{
				second += (100 - first - third - fourth - second);
			}
			return;
		}
		else if (rightAnswer == 3)
		{
			while (first == 0 || second == 0 || third == 0 || fourth == 0 || (third < first + second))
			{
				third = rand() % 50 + (rand() % 50 + 1);
				first = rand() % (100 - third);
				second = rand() % (100 - first - third);
				fourth = rand() % (100 - first - second - third);
			}
			if (first + second + third + fourth < 100)
			{
				third += (100 - first - second - fourth - third);
			}
			return;
		}
		else if (rightAnswer == 4)
		{
			while (first == 0 || second == 0 || third == 0 || fourth == 0 || (fourth < first + second))
			{
				fourth = rand() % 50 + (rand() % 50 + 1);
				first = rand() % (100 - fourth);
				second = rand() % (100 - fourth - first);
				third = rand() % (100 - fourth - first - third);
			}
			if (first + second + third + fourth < 100)
			{
				fourth += (100 - first - second - third - fourth);
			}
			return;
		}
		return;
	}
	void ConvertStringRightAnswerToInt(string rightAnswer, int& rightAnswerCastedToInt)
	{
		if (rightAnswer[0] == 'a')
		{
			rightAnswerCastedToInt = 1;
		}
		else if (rightAnswer[0] == 'b')
		{
			rightAnswerCastedToInt = 2;
		}
		else if (rightAnswer[0] == 'c')
		{
			rightAnswerCastedToInt = 3;
		}
		else if (rightAnswer[0] == 'd')
		{
			rightAnswerCastedToInt = 4;
		}
	}
	void useAudience(string rightAnswer, int difficulty, int& first, int& second, int& third, int &fourth)
	{
		int chanceOfGettingWrongAnswer =rand() % 100;
		int rightAnswerCastedToInt;
		ConvertStringRightAnswerToInt(rightAnswer, rightAnswerCastedToInt);
		if (difficulty>=1 && difficulty<=3)
		{
			if (chanceOfGettingWrongAnswer<30)
			{
				getRandomProcentageToAnswersWhenIsWrong(rightAnswerCastedToInt, first, second, third, fourth);
					return;
			}
			getRandomProcentageToAnswersWhenIsRight(rightAnswerCastedToInt, first, second, third, fourth);
			return;
		}
		else if (difficulty >= 4 && difficulty <= 7)
		{
			if (chanceOfGettingWrongAnswer < 60)
			{
				getRandomProcentageToAnswersWhenIsWrong(rightAnswerCastedToInt, first, second, third, fourth);
				return;
			}
			getRandomProcentageToAnswersWhenIsRight(rightAnswerCastedToInt, first, second, third, fourth);
			return;
		}
		else if (difficulty >= 8 && difficulty <= 10)
		{
			if (chanceOfGettingWrongAnswer < 80)
			{
				getRandomProcentageToAnswersWhenIsWrong(rightAnswerCastedToInt, first, second, third, fourth);
				return;
			}
			getRandomProcentageToAnswersWhenIsRight(rightAnswerCastedToInt, first, second, third, fourth);
			return;
		}
	}
	int CallFriend(string rightAnswer, int difficulty)
	{
		int chanceForWrongAnswer = rand() % 100;
		int answer = 0;
		int rightAnswerCastedToInt;
		ConvertStringRightAnswerToInt(rightAnswer, rightAnswerCastedToInt);
		if (difficulty >= 1 && difficulty <= 3)
		{
			if (chanceForWrongAnswer < 30)
			{
				answer = generateWrongAnswer(rightAnswerCastedToInt);
			}
			answer = rightAnswerCastedToInt;
		}
		else if (difficulty >= 4 && difficulty <= 7)
		{
			if (chanceForWrongAnswer < 60)
			{
				answer = generateWrongAnswer(rightAnswerCastedToInt);
			}
			answer = rightAnswerCastedToInt;
		}
		else if (difficulty >= 8 && difficulty <= 10)
		{
			if (chanceForWrongAnswer < 80)
			{
				answer = generateWrongAnswer(rightAnswerCastedToInt);
			}
			answer = rightAnswerCastedToInt;
		}
		return answer;
	}
//=========================================
	void printDownFrame()
	{
		cout << setw(60) << setfill('=') << "" << endl;
	}
	void printUpperFrame()
	{
		cout << setw(30) << setfill('=') << "Get Rich" << setw(30) << setfill('=') << "" << endl;
	}
	void printMainMenu()
	{
		printUpperFrame();
		cout << setw(30) << setfill(' ') << "1.New game" << endl;
		cout << setw(37) << setfill(' ') << "2.Writing new question" << endl;
		cout << setw(39) << setfill(' ') << "3.Change existing question" << endl;
		cout << setw(28) << setfill(' ') << "4.Exit" << endl;
		printDownFrame();
	}
	void writeIndent(int currentIdent)
	{
		ofstream file;
		file.open("questionNumber.txt");
		file << currentIdent;
		file.close();
	}
	int getNextIdent()
	{
		ifstream input;
		input.open("questionNumber.txt");
		int a=0;
		input >> a;
		a += 1;
		input.close();
		return a;
	}
	void OutputQuestionToFile(string question, string answer1, string answer2, string answer3, string answer4,char rigthAnswer,int category, int difficulty)
	{
		int nextIdent = getNextIdent();
		string fileName = getFileName(difficulty);
		ofstream file;
		file.open(fileName, ostream::app);
		file << nextIdent<< QUESTION_DELIMITER<< category<< QUESTION_DELIMITER<< question << QUESTION_DELIMITER<< answer1 << QUESTION_DELIMITER<< answer2
			<< QUESTION_DELIMITER << answer3 << QUESTION_DELIMITER << answer4 << QUESTION_DELIMITER<< rigthAnswer<<"\n";
		file.close();
		writeIndent(nextIdent);

	}
	int findQuestion(int identNumber)
	{
		int fileNumber=-1;
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
				if ((buffer[0]-'0') == identNumber)
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
	void InsertQuestionFromUser(string& Question, string &answerA, string &answerB, string& answerC, string &answerD, char& rightAnswer, int& Category, int& Difficult )
	{
		string categoryString;
		cout << "How difficult the question is (1-10): ";
		cin >> Difficult;
		while (Difficult < 1 || Difficult>10)
		{
			cout << "Wrong number try new one: ";
			cin >> Difficult;
		}
		cout << endl << "Which category is the question: ";
		cin >> categoryString;
		while (categoryString != "Politics" && categoryString != "History" && categoryString != "Geography" && categoryString != "Literature" && categoryString != "Physics" && categoryString != "All category")
		{
			cout << "Wrong category try new one: ";
			cin >> categoryString;
		}
		if (categoryString== "Politics")
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
	bool CheckForCurrectInputInMenu(int b)
	{
		return b == 1 || b == 2 || b == 3 || b == 4;
	}
	void choosingGame(int &counter, int& choice, string &UserChoice) {
		cout << "\x1B[2J\x1B[H";
		bool x = true;
		bool y = true;
		bool z = true;
		while (true)
		{
			printUpperFrame();
			cout << "Question Number: " << counter << endl;
			string* question = randomQuestion(counter, choice);
			for (size_t i = 2; i < QUESTION_ATTRIBUTES - 1; i++)
			{
				cout << question[i] << endl;
			}
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
				for (size_t i = 2; i < QUESTION_ATTRIBUTES - 1; i++)
				{
					cout << question[i] << endl;
				}
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
				for (size_t i = 2; i < QUESTION_ATTRIBUTES - 1; i++)
				{
					cout << question[i] << endl;
				}
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