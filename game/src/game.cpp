#include "game.h"

Game::Game(int width, int height) : IApplication(width, height)
{
	_hitman = nullptr;
}

Game::~Game()
{
	delete _hitman;
}

void Game::Run()
{
	InitWindow(screenSize.x, screenSize.y, "Game");
	SetTargetFPS(60);

	_hitman = new Hitman("resources/hitman1_gun.png", screenSize * .5f, 100.0f);

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		_hitman->Update(dt);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode2D(cam);
		_hitman->Draw();
		EndMode2D();

		EndDrawing();
	}

	CloseWindow();
}
