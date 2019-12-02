#pragma once
#include<vector>
#include "ActionUnit.h"

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

    //  get (modifiable)
    ActionUnit& GetPlayer();
    ActionUnit& GetEnemy();
    std::vector<Skill>& GetSkillSlot();

    //  other
    void Start();
};