#pragma once
#include "ActionUnit.h"
#include "BattleManager.h"
#include "ConsoleEngine/ConsoleEngine.h"
#include <string>
using namespace ConsoleEngine;

class BattleInterfaceRender
{
private:
	BattleManager battleManager;

	//	render layers
	ConsoleScene interfaceFrame;
	ConsoleScene actionUnitData;
	ConsoleScene actionUnitImage;
	ConsoleScene skills;
	ConsoleScene slots;

	//	shortcut pointer
	ConsoleText* slot1;
	ConsoleText* slot2;
	ConsoleText* slot3;
	ConsoleText* playerLife;
	ConsoleText* enemyLife;

	explicit BattleInterfaceRender();
public:
	//	constructor
	BattleInterfaceRender(const BattleManager& CurrentBattleManager);

	//	render
	void InitialRender()const;
	void InterfaceFrame()const;
	void ActionUnitImage()const;
	void Skills()const;

	//	update and render
	void ActionUnitData();
	void Slots();
};