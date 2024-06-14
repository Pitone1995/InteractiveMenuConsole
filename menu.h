#ifndef MENU_H
#define MENU_H

class Menu {

public:
	Menu();

	void run();
	void show();

private:
	void selOption();
	int selIndex = 0;
	bool quit = false;
};

#endif
