#pragma once
#include "ActionUnit.h"
#include "BattleManager.h"
#include "ConsoleEngine/ConsoleEngine.h"
#include <string>
using namespace ConsoleEngine;

class BattleInterfaceRender
{
private:
	ConsoleScene scene;

	void Centered(const std::string text, const int x, const int y);
public:
	BattleInterfaceRender(const BattleManager& battleManager);
	void Initialize();
};