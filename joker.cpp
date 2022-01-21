#include "joker.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
int generateWrongAnswer(int rightAnswer) {
	int answer;
	answer = rand() % 4 + 1;
	while (answer == rightAnswer && answer == 0) {
		answer = rand() % 4 + 1;
	}
	return answer;
}
void useFiftyFifty(string rightAnswer, int& eliminated1, int& eliminated2)
{
	int rightAnswerCastedToInt = 0;
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
	if (answer == 1)
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
			first += (100 - second - third - fourth - first);
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
			second += (100 - first - third - fourth - second);
		}
		return;
	}
	else if (answer == 3)
	{
		while (first == 0 && second == 0 && third == 0 && fourth == 0)
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
			fourth += (100 - first - second - third - fourth);
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
void useAudience(string rightAnswer, int difficulty, int& first, int& second, int& third, int& fourth)
{
	int chanceOfGettingWrongAnswer = rand() % 100;
	int rightAnswerCastedToInt;
	ConvertStringRightAnswerToInt(rightAnswer, rightAnswerCastedToInt);
	if (difficulty >= 1 && difficulty <= 3)
	{
		if (chanceOfGettingWrongAnswer < 30)
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