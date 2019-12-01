#pragma once
#include "ActionUnit.h"
#include<vector>

class BattleManager
{
private:
    ActionUnit _player;
    ActionUnit _enemy;
    std::vector<Skill>_skillSlot;

public:
    //  contrustor
    BattleManager();
    BattleManager(const BattleManager& Manager);

    //  get
    const ActionUnit& GetPlayer()const;
    const ActionUnit& GetEnemy()const;
    const std::vector<Skill>& GetSkillSlot()const;

    void Start();
};