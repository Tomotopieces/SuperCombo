#include "BattleInterfaceRender.h"
#include "ConsoleEngine/ConsoleEngine.h"
#include <iostream>
#include <functional>
using namespace ConsoleEngine;

short WindowWidth = 97;
short WindowHeight = 32;

BattleInterfaceRender::BattleInterfaceRender(const BattleManager& CurrentBattleManager)
	: battleManager(CurrentBattleManager)
{
	//	render top and bottom line
	std::string line;
	for (int i = 0; i < WindowWidth - 1; ++i)
		line += '=';
	ConsoleText cLine = line;
	cLine.SetForeColor(cyan);
	interfaceFrame.AddObject(cLine, 1, 0).AddObject(cLine, 1, WindowHeight);

	//	render skill slot middle line
	line.clear();
	for (int i = 0; i < 16; ++i)
		line += '=';
	cLine = line;
	cLine.SetForeColor(cyan + light);
	interfaceFrame.AddObject(cLine, 1, 23).AddObject(cLine, WindowWidth - 16, 23);

	//	render slot frame
	line.clear();
	for (int i = 0; i < 20; ++i) {
		line += '=';
	}
	cLine = line;
	interfaceFrame.AddObject(cLine, 18, 22).AddObject(cLine, 18, 24);
	interfaceFrame.AddObject(cLine, 39, 22).AddObject(cLine, 39, 24);
	interfaceFrame.AddObject(cLine, 60, 22).AddObject(cLine, 60, 24);

	//	add skill slot
	ConsoleButton slot(battleManager.skillslot[0].Getname());
	slot.SetDraggable(true);
	slot.SetRenderMode(PointCentered);
	slots.AddObject(slot, 28, 23);
	slots.AddObject(slot.SetText(battleManager.skillslot[1].Getname()), 49, 23);	//	rename and then add
	slots.AddObject(slot.SetText(battleManager.skillslot[2].Getname()), 70, 23);	//	ibid
	slot1 = dynamic_cast<ConsoleText*>(slots[0]);
	slot2 = dynamic_cast<ConsoleText*>(slots[1]);
	slot3 = dynamic_cast<ConsoleText*>(slots[2]);

	//	add player and enemy Life data
	ConsoleText PlayerLife(std::to_string(battleManager.player.GetLife()) + "/" + std::to_string(battleManager.player.GetMaximumLife()));
	PlayerLife.SetRenderMode(PointCentered);
	ConsoleText EnemyLife(std::to_string(battleManager.enemy.GetLife()) + "/" + std::to_string(battleManager.enemy.GetMaximumLife()));
	EnemyLife.SetRenderMode(PointCentered);
	actionUnitData.AddObject(PlayerLife, 22, 17).AddObject(EnemyLife, 71, 17);
	playerLife = dynamic_cast<ConsoleText*>(actionUnitData[0]);
	enemyLife = dynamic_cast<ConsoleText*>(actionUnitData[1]);

	//	add player and enemy image
	actionUnitImage.AddObject(battleManager.player.GetImage(), 20, 18);
	actionUnitImage.AddObject(battleManager.enemy.GetImage(), 69, 18);


	//	add optional skills
	for (int i = 0; i < battleManager.player.GetCountOfSkill(); ++i) {
		ConsoleText skill(battleManager.player.GetSkillName(i), 10 + i * 20, 26);
		skills.AddObject(skill);
	}
}

void BattleInterfaceRender::InitialRender() const
{
	interfaceFrame.Render();
	actionUnitData.Render();
	actionUnitImage.Render();
	slots.Render();
	skills.Render();
}

void BattleInterfaceRender::InterfaceFrame() const
{
	interfaceFrame.Render();
}

void BattleInterfaceRender::ActionUnitImage() const
{
	actionUnitData.Render();
}

void BattleInterfaceRender::Skills() const
{
	skills.Render();
}

void BattleInterfaceRender::ActionUnitData()
{
	playerLife->SetText(std::to_string(battleManager.player.GetLife()) + "/" + std::to_string(battleManager.player.GetMaximumLife()));
	enemyLife->SetText(std::to_string(battleManager.enemy.GetLife()) + "/" + std::to_string(battleManager.enemy.GetMaximumLife()));
	actionUnitData.Render();
}

void BattleInterfaceRender::Slots()
{
	slot1->SetText(battleManager.skillslot[0].Getname());
	slot2->SetText(battleManager.skillslot[1].Getname());
	slot3->SetText(battleManager.skillslot[2].Getname());
	slots.Render();
}
