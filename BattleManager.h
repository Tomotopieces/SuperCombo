#pragma once
#include "ActionUnit.h"
#include<vector>

class BattleManager
{
public:
	ActionUnit player;
	ActionUnit enemy;
	std::vector<Skill>skillslot;

public:
	BattleManager();
	BattleManager(const BattleManager& Manager);

	void Start();
};