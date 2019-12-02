#pragma once
#include <string>

class BattleManager;

class Skill
{
private:
    std::string _name;
    void(*_effect)(BattleManager&);
public:
    Skill();
    Skill(const std::string name, void(*effect)(BattleManager&));
    Skill(const Skill& skill);
    Skill(Skill&& skill);
    const Skill& operator=(const Skill& skill);
    const bool operator==(const Skill& skill);

    //  get
    const std::string Getname()const;
    const Skill& Launch(BattleManager& battleManager)const;

    //  set
    Skill& SetEffect(void(*effect)(BattleManager&));
};