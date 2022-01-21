#pragma once
#include <iostream>
using namespace std;
int generateWrongAnswer(int rightAnswer);
void useFiftyFifty(string rightAnswer, int& eliminated1, int& eliminated2);
void getRandomProcentageToAnswersWhenIsWrong(int rightAnswer, int& first, int& second, int& third, int& fourth);
void getRandomProcentageToAnswersWhenIsRight(int rightAnswer, int& first, int& second, int& third, int& fourth);
void ConvertStringRightAnswerToInt(string rightAnswer, int& rightAnswerCastedToInt);
void useAudience(string rightAnswer, int difficulty, int& first, int& second, int& third, int& fourth);
int CallFriend(string rightAnswer, int difficulty);
int main();;