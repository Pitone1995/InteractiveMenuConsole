#include "menu.h"

#include "ConsoleUtils.h"
#include <conio.h>

#define UP_ARROW 72
#define DWN_ARROW 80
#define ENTER 13

enum {

	NEW,
	LOAD,
	QUIT
};

using namespace std;

Menu::Menu() {
	
	Console::ShowConsoleCursor(false);
	show();
}

Menu::~Menu() {

	Console::ShowConsoleCursor(true);
	Console::resetColor();
	system("cls");
	system("color");
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
			show();
			break;

		default:
			break;
		}
	}
}

void Menu::show() {

	Console::resetColor();
	system("cls");

	switch (selIndex) {

		case 0:
			Console::setColor(HIGHLIGHT_TXT);
			cout << "New game\n";
			Console::resetColor();
			cout << "Load game\n";
			cout << "Quit\n";
			break;
		
		case 1:
			cout << "New game" << endl;
			Console::setColor(HIGHLIGHT_TXT);
			cout << "Load game" << endl;
			Console::resetColor();
			cout << "Quit" << endl;
			break;

		case 2:
			cout << "New game" << endl;
			cout << "Load game" << endl;
			Console::setColor(HIGHLIGHT_TXT);
			cout << "Quit" << endl;
			break;

		default:
			break;
	}
}

void Menu::selOption() {

	switch (selIndex) {

	case NEW:
		cout << "New game selected" << endl;
		break;

	case LOAD:
		cout << "Load game selected" << endl;
		break;

	default: // QUIT
		// Console::resetColor();
		quit = true;
		break;
	}
}