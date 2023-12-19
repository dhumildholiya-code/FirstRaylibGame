#include "editor.h"

Editor::Editor(int width, int height) : IApplication(width, height)
{
}

Editor::~Editor()
{
}

void Editor::Run()
{
	InitWindow(screenSize.x, screenSize.y, "Game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();

		BeginDrawing();
		ClearBackground(BLACK);

		BeginMode2D(cam);
		EndMode2D();

		EndDrawing();
	}

	CloseWindow();
}
