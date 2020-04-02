#include <easyx.h>
#include "display.h"


Window::Window() {


	initgraph(HORIZONTAL, VERITCAL);

	setbkcolor(this->NightClub.zero);
	clearrectangle(0, 0, HORIZONTAL, VERITCAL);
}

void Window::printTrace() {
	if (this->map[this->antRow][this->antColumn])
		setfillcolor(this->NightClub.zero);
	else
		setfillcolor(this->NightClub.one);
	solidrectangle(this->antRow * CUBE, this->antColumn * CUBE,
		(this->antRow + 1) * CUBE - 1, (this->antColumn + 1) * CUBE - 1);
}

void Window::printAnt() {
	setfillcolor(this->NightClub.ant);
	solidrectangle(this->antRow * CUBE + 2, this->antColumn * CUBE + 2,
		(this->antRow + 1) * CUBE - 3, (this->antColumn + 1) * CUBE - 3);
}

void Window::printStep(int step) {
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 20;
	f.lfWidth = 10;
	f.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(f.lfFaceName, _T("Jetbrains Mono"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(this->NightClub.one);
	wchar_t temp[7];
	wsprintf(temp, L"%d", step);
	outtextxy(16, 16, temp);

}
