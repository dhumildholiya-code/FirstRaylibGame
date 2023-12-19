#pragma once
#include "application.h"

class Editor : public IApplication
{
public:
	Editor(int width, int height);
	~Editor();
public:
	// Inherited via IApplication
	void Run() override;
};
