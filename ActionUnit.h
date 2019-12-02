#pragma once
#include "Skill.h"
#include "ConsoleEngine/ConsoleEngine.h"
using namespace console_engine;

class ActionUnit
{
private:
    std::string _name;
    int _maximumLife;
    int _life;
    int _maximumMana;
    int _mana;
    int _attack;
    int _defense;
    int _armor;
    std::vector<Skill> _learnedSkills;
    ConsoleImage _image;
public:
    //  constructor
    ActionUnit();
    ActionUnit(const std::string name);
    ActionUnit(const ActionUnit& unit);
    ActionUnit(ActionUnit&& unit);
    const ActionUnit& operator=(const ActionUnit& unit);

    //  get
    const std::string GetName()const;
    const int GetMaximumLife()const;
    const int GetLife()const;
    const int GetMaximumMana()const;
    const int GetMana()const;
    const int GetAttack()const;
    const int GetDefense()const;
    const int GetArmor()const;
    const int GetCountOfSkill()const;
    const std::string GetSkillName(const int number)const;
    const ConsoleImage& GetImage()const;

    //  set
    ActionUnit& SetName(const std::string name);
    ActionUnit& SetMaximumLife(const int maximumLife);
    ActionUnit& SetLife(const int life);
    ActionUnit& SetMaximumMana(const int mana);
    ActionUnit& SetAttack(const int attack);
    ActionUnit& SetDefense(const int defense);
    ActionUnit& SetImage(const RawImage& image);
    ActionUnit& SetImage(const ConsoleImage& image);

    //  others
    ActionUnit& AddSkill(const Skill skill);
    ActionUnit& RemoveSkill(const Skill targetSkill);
};