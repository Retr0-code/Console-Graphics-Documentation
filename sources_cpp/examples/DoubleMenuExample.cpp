﻿#include "../sources/Semi-Graphics.h"

#define FONT_SIZE 36
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 820

void A()
{
	cls(GetStdHandle(STD_OUTPUT_HANDLE));
	std::cout << "\n Yep ";
}

void B()
{
	cls(GetStdHandle(STD_OUTPUT_HANDLE));
	std::cout << "\n Not that ";
}

void C()
{
	cls(GetStdHandle(STD_OUTPUT_HANDLE));
	std::cout << "\n Not that one ";
}

void D()
{
	cls(GetStdHandle(STD_OUTPUT_HANDLE));
	std::cout << "\n That a lot more ";
}



// ---------- Child classes ------------ //

class firstParagraph : public PARAGRAPH
{
public:
	firstParagraph(std::string _paragraphName, std::string _description) : PARAGRAPH(_paragraphName, _description)
	{
		paragraphName = _paragraphName;
		description = _description;
	}

	void Execute() override
	{
		A();
	}
};

class secondParagraph : public PARAGRAPH
{
public:
	secondParagraph(std::string _paragraphName, std::string _description) : PARAGRAPH(_paragraphName, _description)
	{
		paragraphName = _paragraphName;
		description = _description;
	}

	void Execute() override
	{
		B();
	}
};

class thirdParagraph : public PARAGRAPH
{
public:
	thirdParagraph(std::string _paragraphName, std::string _description) : PARAGRAPH(_paragraphName, _description)
	{
		paragraphName = _paragraphName;
		description = _description;
	}

	void Execute() override
	{
		C();
	}
};

class fourthParagraph : public PARAGRAPH
{
public:
	fourthParagraph(std::string _paragraphName, std::string _description) : PARAGRAPH(_paragraphName, _description)
	{
		paragraphName = _paragraphName;
		description = _description;
	}

	void Execute() override
	{
		D();
	}
};

int main()
{
	Graphics window(WINDOW_WIDTH, WINDOW_HEIGHT, {BG_BLACK, FG_WHITE}, {BG_ORANGE, FG_BLACK}, FONT_SIZE);

	//window.makeFrame(0, 0, WINDOW_WIDTH / 10 - calculatePercent((WINDOW_WIDTH / 10), 11), WINDOW_HEIGHT / 10 - calculatePercent(WINDOW_HEIGHT / 10, 80) );
	Frame frame(0, 1, (WINDOW_WIDTH / FONT_SIZE) * 2 - 4, WINDOW_HEIGHT / (FONT_SIZE * 2));
	frame.spawnFrame();

	std::string menuNames[4] = { "1 MENU" , "2 HELP", "3 TEST", "4 EXIT" };
	std::string menuDescriptions[4] = { "Displays this menu message", "Displays help message     ", "Displays message with test", "Shuts down the program    " };

	// ----------- Creating paragraphs objects ------------- //

	firstParagraph* fstPar = new firstParagraph(menuNames[0], menuDescriptions[0]);
	secondParagraph* sndPar = new secondParagraph(menuNames[1], menuDescriptions[1]);
	thirdParagraph* trdPar = new thirdParagraph(menuNames[2], menuDescriptions[2]);
	fourthParagraph* frtPar = new fourthParagraph(menuNames[3], menuDescriptions[3]);

	PARAGRAPH* objects[4] = { fstPar, sndPar, trdPar, frtPar };

	// ----------- Initialize Menu ----------- //

	Menu* menu1 = new Menu(4, 10, 13, objects, window, frame);
	Menu* menu2 = new Menu(4, objects, window, frame);
	Menu switch2Menu(4, objects, window, frame);

	// Creates two vertical menu orientation
	switch2Menu.switchMenu(menu1, menu2, &Menu::vertical, &Menu::vertical);

	
	system("pause");

	// Removing paragraphs objects to escape memory leak
	delete fstPar, sndPar, trdPar, frtPar, objects;
	delete menu1, menu2;
	SecureZeroMemory(menuNames, sizeof(menuNames));
	SecureZeroMemory(menuDescriptions, sizeof(menuNames));

	return 0;
}