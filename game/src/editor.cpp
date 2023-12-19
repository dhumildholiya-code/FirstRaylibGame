#include "editor.h"

Editor::Editor(int width, int height) : IApplication(width, height)
{
}

Editor::~Editor()
{
	UnloadTexture(_tileMap);
}

void Editor::LoadTileMap()
{
	_tileMap = LoadTexture("resources/tilesheet.png");
}

void Editor::DrawGrid()
{
	int hGridSize = _tileMap.width / gridSize;
	int vGridSize = _tileMap.height / gridSize;

	for (size_t i = 0; i < hGridSize; i++)
	{
		DrawLine(i * gridSize, 0, i * gridSize, _tileMap.height, BLUE);
	}
	for (size_t i = 0; i < vGridSize; i++)
	{
		DrawLine(0, i * gridSize, _tileMap.width, i * gridSize, BLUE);
	}
}

void Editor::PanCamera()
{
	if (IsMouseButtonDown(0))
	{
		cam.target = Vector2Add(GetMousePosition(), _panOffset);
	}
	else
	{
		_panOffset = Vector2Subtract(cam.target, GetMousePosition());
	}
}

void Editor::Run()
{
	InitWindow(screenSize.x, screenSize.y, "Editor");
	SetTargetFPS(60);

	LoadTileMap();

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		PanCamera();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		//Draw UI Code

		BeginMode2D(cam);

		//Draw Code
		DrawTexture(_tileMap, 0, 0, WHITE);
		DrawGrid();

		EndMode2D();

		EndDrawing();
	}

	CloseWindow();
}
