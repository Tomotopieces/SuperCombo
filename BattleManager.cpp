#include "BattleManager.h"
#include "BattleInterfaceRender.h"
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
	BattleInterfaceRender render(*this);
	render.InitialRender();
}

BattleManager::BattleManager(const BattleManager& Manager)
	: player(Manager.player)
	, enemy(Manager.enemy)
	, skillslot(Manager.skillslot)
{
}
