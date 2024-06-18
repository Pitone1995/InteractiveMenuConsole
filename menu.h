#ifndef menu_H
#define menu_H

class Menu {

public:
	Menu();
	~Menu();

	void run();
	void show();

private:
	void selOption();
	int selIndex = 0;
	bool quit = false;
};

#endif
