#include <iostream>
#include <easyx.h>
#include <conio.h>
#include "display.h"
#include "brain.h"

using namespace std;

int main()
{
	Window Play;
	//Sleep(10000);
	for (int i = 0; i <= 11000; i++) {
		Play.printTrace();
		Play.nextStep();
		Play.printAnt();
		Play.printStep(i);
		Sleep(100);
	}
	_getch();
	return 0;
}
