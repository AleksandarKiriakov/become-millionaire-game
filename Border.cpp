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