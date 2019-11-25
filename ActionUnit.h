#pragma once
#include "Skill.h"
#include "ConsoleEngine/ConsoleEngine.h"
#include <string>
#include <vector>
using namespace ConsoleEngine;

class ActionUnit
{
private:
	std::string name;
	int maximumLife;
	int life;
	int maximumMana;
	int mana;
	int attack;
	int defensive;
	int armor;
	std::vector<Skill> learnedSkills;
	ConsoleImage image;
public:
	//	constructor
	ActionUnit();
	ActionUnit(const std::string Name);
	ActionUnit(const ActionUnit& Player2);
	ActionUnit(ActionUnit&& Player2);
	const ActionUnit& operator=(const ActionUnit& Player2);

	//	get
	const std::string GetName()const;
	const int GetMaximumLife()const;
	const int GetLife()const;
	const int GetMaximumMana()const;
	const int GetMana()const;
	const int GetAttack()const;
	const int GetDefensive()const;
	const int GetCountOfSkill()const;
	const std::string GetSkillName(const int number)const;
	const ConsoleImage& GetImage()const;

	//	set
	ActionUnit& SetName(const std::string Name);
	ActionUnit& SetMaximumLife(const int MaximumLife);
	ActionUnit& SetLife(const int Life);
	ActionUnit& SetMaximumMana(const int Mana);
	ActionUnit& SetAttack(const int Attack);
	ActionUnit& SetDefensive(const int Defensive);
	ActionUnit& SetImage(const RawImage& Image);
	ActionUnit& SetImage(const ConsoleImage& Image);

	//	others
	ActionUnit& AddSkill(const Skill newSkill);
	ActionUnit& RemoveSkill(const Skill targetSkill);
};