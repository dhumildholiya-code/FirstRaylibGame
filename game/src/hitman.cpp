#include "hitman.h"

Hitman::Hitman(const std::string& path, Vec2 posIn, float speedIn)
	:
	_speed{ speedIn }
{
	_tex = LoadTexture(path.c_str());
	position = posIn;
	rotation = 0.0f;
	scale = Vec2(1.0f, 1.0f);
	_origin = Vector2{_tex.width * .5f, _tex.height * .5f};
	_srcRec = { 0.0f,0.0f, _tex.width * 1.0f, _tex.height * 1.0f };
	_destRec = { position.x, position.y, _tex.width * scale.x, _tex.height * scale.y };
}

Hitman::~Hitman()
{
	UnloadTexture(_tex);
}

void Hitman::Draw()
{
	_destRec = { position.x, position.y, _tex.width * scale.x, _tex.height * scale.y };
	DrawTexturePro(_tex, _srcRec, _destRec, _origin, rotation, WHITE);
}

void Hitman::Update(float dt)
{
	//Input Handling
	Vec2 inputVec = Vec2::zero();
	if (IsKeyDown(KEY_W))
	{
		inputVec.y = -1.0f;
	}
	else if (IsKeyDown(KEY_S))
	{
		inputVec.y = 1.0f;
	}
	if (IsKeyDown(KEY_A))
	{
		inputVec.x = -1.0f;
	}
	else if (IsKeyDown(KEY_D))
	{
		inputVec.x = 1.0f;
	}
	inputVec.normalize();

	position += inputVec * _speed * dt;

	//handle rotation
	Vec2 mouseDir = Vec2(GetMouseX() - position.x, GetMouseY() - position.y);
	mouseDir.normalize();
	rotation = atan2f(mouseDir.y, mouseDir.x) * RAD2DEG;
}
