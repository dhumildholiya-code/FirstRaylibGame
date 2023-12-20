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
	Map map = Map();
	//map.AddTile(Rectangle{ 0,0,64,64 }, "Grass_1");
	//map.AddTile(Rectangle{ 64,0,64,64 }, "Grass_2");
	map.Print();
	map.Deserialize();
	map.Print();
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

	DrawRectangle(_mousePos.x * gridSize, _mousePos.y * gridSize, gridSize, gridSize, Color{ 255,0,0,100 });
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
		_mousePos = Vec2(floorf(GetMouseX() * 1.0f / gridSize), floorf(GetMouseY() * 1.0f / gridSize));

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
