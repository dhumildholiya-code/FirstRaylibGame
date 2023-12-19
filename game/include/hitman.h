#pragma once
#include "raylib.h"
#include "math/vec2.h"

class Hitman {
public:
	Vec2 position;
	Vec2 scale;
	float rotation;

private:
	Texture2D _tex;
	Rectangle _srcRec;
	Rectangle _destRec;
	Vector2 _origin;
	float _speed;

public:
	Hitman(const std::string& path, Vec2 posIn, float speedIn);
	~Hitman();
	void Update(float dt);
	void Draw();
};
