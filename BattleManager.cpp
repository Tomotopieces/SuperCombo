#include "BattleManager.h"
#include "Render.h"
#include "SkillList.h"

BattleManager::BattleManager()
	: player()
	, enemy()
{
	skillslot.push_back(Empty);
	skillslot.push_back(Empty);
	skillslot.push_back(Empty);
	RawImage image =
	{
		"$O$",
		"/|\\",
		"/$\\"
	};
	ConsoleImage cImage = image;
	cImage.SetAllColor(black, yellow + light);
	player.SetImage(cImage);
	cImage.SetAllColor(black, red + light);
	enemy.SetImage(cImage);
	player.SetAttack(10);
	enemy.SetLife(1);
	BattleInterfaceRender render(*this);
	render.Initialize();
}
