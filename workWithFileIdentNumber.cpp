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
* <get and write ident to questions>
*
*/

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