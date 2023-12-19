#pragma once
#include "math/vec2.h"
#include "raylib.h"
#include "raymath.h"

class IApplication
{
public:
	Vec2 screenSize;
	Camera2D cam;
public:
	IApplication(int width, int height)
	{
		screenSize = Vec2(width, height);
		SetupCamera();
	}
	virtual void Run() = 0;

private:
	void SetupCamera()
	{
		cam.offset.x = 0.0f; cam.offset.y = 0.0f;
		cam.rotation = 0.0f;
		cam.target.x = 0.0f; cam.target.y = 0.0f;
		cam.zoom = 1.0f;
	}
};
