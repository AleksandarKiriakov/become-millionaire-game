#include <fstream>
using namespace std;
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
	int a = 0;
	input >> a;
	a += 1;
	input.close();
	return a;
}