#include <iostream>
#include "raylib.h"
#include "math/vec2.h"

void drawVec(const Vec2& vec, const Color& col) {
	Vec2 origin;
	DrawCircle(vec.x, vec.y, 4.0, col);
	DrawLine(origin.x, origin.y, vec.x, vec.y, col);
}

int main(void)
{
	InitWindow(800, 450, "raylib [core] example - basic window");

	Camera2D cam;
	cam.offset.x = 400.0; cam.offset.y = 225.0;
	cam.rotation = 0.0;
	cam.target.x = 0.0; cam.target.y = 0.0;
	cam.zoom = 1.0;

	Vec2 a(100.0, 100.0);
	Vec2 b(0.0, -100.0);
	Vec2 c(100.0, 0.0);
	Vec2 d(-100.0, 0.0);

	b += c;
	float angleab = Vec2::angle(b, a);
	std::cout << angleab * RAD2DEG << std::endl;
	a.rotateBy(180.0f);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode2D(cam);
		drawVec(a, BLACK);
		drawVec(b, GREEN);
		drawVec(c, YELLOW);
		drawVec(d, BLUE);
		EndMode2D();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}