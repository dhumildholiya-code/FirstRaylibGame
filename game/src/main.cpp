#include <iostream>
#include "editor.h"
#include "game.h"

int main(void)
{
	bool isEditor = true;
	IApplication* app = nullptr;

	if (isEditor)
	{
		app = new Editor(800, 600);
	}
	else
	{
		app = new Game(800, 600);
	}

	app->Run();

	delete app;
	return 0;
}