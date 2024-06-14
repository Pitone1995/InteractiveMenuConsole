#include "menu.h"
#include <iostream>
#include <conio.h>
#include "windows.h"

#define UP_ARROW 72
#define DWN_ARROW 80
#define ENTER 13

#define HIGHLIGHT_TXT 240
#define DEFAULT_TXT 15

enum {

	NEW,
	LOAD,
	QUIT
};

using namespace std;

Menu::Menu() {
	
	show();
}

void Menu::run() {

	int key = 0;

	while (!quit) {

		key = _getch();

		/* getch () function returns two keycodes for arrow keys. Arrow put to getch '\033' and '[' and letter from A to D (up, down, right, left).
		Check if the first value is escape and skip */
		if (key == 224)
			key = _getch();

		switch (key) {

		case UP_ARROW:
			selIndex--;
			if (selIndex == -1)
				selIndex = 2;
			show();
			break;

		case DWN_ARROW:
			selIndex++;
			if (selIndex == 3)
				selIndex = 0;
			show();
			break;

		case ENTER:
			selOption();
			break;

		default:
			break;
		}
	}
}

void Menu::show() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, DEFAULT_TXT);

	system("cls");

	switch (selIndex) {

		case 0:
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_TXT);
			cout << "New game\n";
			SetConsoleTextAttribute(hConsole, DEFAULT_TXT);
			cout << "Load game\n";
			SetConsoleTextAttribute(hConsole, DEFAULT_TXT);
			cout << "Quit\n";
			break;
		
		case 1:
			SetConsoleTextAttribute(hConsole, DEFAULT_TXT);
			cout << "New game" << endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_TXT);
			cout << "Load game" << endl;
			SetConsoleTextAttribute(hConsole, DEFAULT_TXT);
			cout << "Quit" << endl;
			break;

		case 2:
			SetConsoleTextAttribute(hConsole, DEFAULT_TXT);
			cout << "New game" << endl;
			SetConsoleTextAttribute(hConsole, DEFAULT_TXT);
			cout << "Load game" << endl;
			SetConsoleTextAttribute(hConsole, HIGHLIGHT_TXT);
			cout << "Quit" << endl;
			break;

		default:
			break;
	}
}

void Menu::selOption() {

	switch (selIndex) {

	case NEW:
		cout << "Hai selezionato New game" << endl;
		break;

	case LOAD:
		cout << "Hai selezionato Load game" << endl;
		break;

	default: // QUIT
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		quit = true;
		break;
	}
}