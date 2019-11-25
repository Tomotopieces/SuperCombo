#include "Render.h"
#include "ConsoleEngine/ConsoleEngine.h"
#include <iostream>
using namespace ConsoleEngine;

short WindowWidth = 97;
short WindowHeight = 32;

void BattleInterfaceRender::Centered(const std::string text, const int x, const int y)
{
	Cursor.SetPosition(x - text.size() / 2, y);
}

BattleInterfaceRender::BattleInterfaceRender(const BattleManager& battleManager)
{
	//	add player and enemy image
	scene.AddObject(battleManager.player.GetImage(), 20, 18).AddObject(battleManager.enemy.GetImage(), 69, 18);

	//	add skill slot
	ConsoleText slot1(battleManager.skillslot[0].Getname(), 28, 23);
	slot1.SetRenderMode(PointCentered);
	ConsoleText slot2(battleManager.skillslot[1].Getname(), 49, 23);
	slot2.SetRenderMode(PointCentered);
	ConsoleText slot3(battleManager.skillslot[2].Getname(), 70, 23);
	slot3.SetRenderMode(PointCentered);
	scene.AddObject(slot1).AddObject(slot2).AddObject(slot3);

	//	add optional skills
	for (int i = 0; i < battleManager.player.GetCountOfSkill(); ++i) {
		ConsoleText skill(battleManager.player.GetSkillName(i), 10 + i * 20, 26);
		scene.AddObject(skill);
	}
}

void BattleInterfaceRender::Initialize()
{
	Character.SetForeColor(cyan + light);

	Screen.SetSize(WindowWidth, WindowHeight);
	Screen.HideScrollBar();
	Screen.SetTitle("Super Console");
	Cursor.Hide();

	//	top and bottom line
	Cursor.SetPosition(1, 0);
	for (int i = 0; i < WindowWidth - 1; ++i)
		std::cout << '=';
	Cursor.SetPosition(1, WindowHeight);
	for (int i = 0; i < WindowWidth - 1; ++i)
		std::cout << '=';

	//	skill slot middle line
	Cursor.SetPosition(1, 23);
	for (int i = 0; i < 16; ++i)
		std::cout << '=';
	Cursor.SetPosition(WindowWidth - 16, 23);
	for (int i = 0; i < 16; ++i)
		std::cout << '=';

	//	slot1 frame
	Cursor.SetPosition(18, 22);
	for (int i = 0; i < 20; ++i)
		std::cout << '=';
	Cursor.SetPosition(18, 24);
	for (int i = 0; i < 20; ++i)
		std::cout << '=';

	//	slot2 frame
	Cursor.SetPosition(39, 22);
	for (int i = 0; i < 20; ++i)
		std::cout << '=';
	Cursor.SetPosition(39, 24);
	for (int i = 0; i < 20; ++i)
		std::cout << '=';

	//	slot3 frame
	Cursor.SetPosition(60, 22);
	for (int i = 0; i < 20; ++i)
		std::cout << '=';
	Cursor.SetPosition(60, 24);
	for (int i = 0; i < 20; ++i)
		std::cout << '=';

	scene.Render();
}
