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
* <printing borders>
*
*/

#include <iostream>
#include <iomanip>
#include "Border.h"
using namespace std;
void printDownFrame()
{
	cout << setw(60) << setfill('=') << "" << endl;
}
void printUpperFrame()
{
	cout << setw(30) << setfill('=') << "Get Rich" << setw(30) << setfill('=') << "" << endl;
}