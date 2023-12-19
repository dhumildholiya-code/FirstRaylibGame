#include <iostream>
#include "raylib.h"
#include "math/vec2.h"
#include "hitman.h"

void drawVec(const Vec2& vec, const Color& col) {
	Vec2 origin;
	DrawCircle(vec.x, vec.y, 4.0, col);
	DrawLine(origin.x, origin.y, vec.x, vec.y, col);
}

int main(void)
{
	const int tileSize = 64;
	const int sWidth = tileSize * 10;
	const int sHeight = tileSize * 7;
	InitWindow(sWidth, sHeight, "raylib [core] example - basic window");
	SetTargetFPS(60);

	int map[70];
	for (size_t i = 0; i < 10 * 7; i++)
	{
		map[i] = rand() % 4;
	}

	Camera2D cam;
	cam.offset.x = 0.0f; cam.offset.y = 0.0f;
	cam.rotation = 0.0f;
	cam.target.x = 0.0f; cam.target.y = 0.0f;
	cam.zoom = 1.0f;

	Texture2D floorTileSet = LoadTexture("resources/tilesheet.png");
	Hitman* hitman = new Hitman("resources/hitman1_gun.png", Vec2(sWidth * .5f, sHeight * .5f), 100.0f);
	Vector2 origin = { 0.0f, 0.0f };
	Rectangle srcRec = { 0.0f, 0.0f, tileSize, tileSize };
	Rectangle destRec = { 0.0f, 0.0f, tileSize, tileSize };

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		hitman->Update(dt);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode2D(cam);
		for (size_t x = 0; x < 10; x++)
		{
			for (size_t y = 0; y < 7; y++)
			{
				srcRec.x = map[x + y * 10] * tileSize;
				destRec.x = x * tileSize; destRec.y = y * tileSize;
				DrawTexturePro(floorTileSet, srcRec, destRec, origin, 0.0f, WHITE);
			}
		}
		hitman->Draw();
		EndMode2D();

		EndDrawing();
	}

	delete hitman;
	CloseWindow();

	return 0;
}