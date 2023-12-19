#pragma once
#include "application.h"
#include "hitman.h"

class Game : public IApplication
{
private:
	Hitman* _hitman;

public:
	Game(int width, int height);
	~Game();
public:
	// Inherited via IApplication
	void Run() override;
};
