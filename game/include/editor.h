#pragma once
#include "application.h"

class Editor : public IApplication
{
private:
	const int gridSize = 64;
	Vector2 _panOffset;
private:
	Texture2D _tileMap;
public:
	Editor(int width, int height);
	~Editor();

private:
	void LoadTileMap();
	void PanCamera();
	void DrawGrid();
public:
	// Inherited via IApplication
	void Run() override;
};
