#include "SkillLibrary.h"
#include "ActionUnit.h"
#include "BattleManager.h"

Skill Empty("Empty", [](BattleManager& battleManager) {});
Skill Beat("Beat", [](BattleManager& battleManager)
    {
        battleManager.GetEnemy().SetLife(
            battleManager.GetEnemy().GetLife() -
            battleManager.GetPlayer().GetAttack()
        );
    }
);
Skill Beat2("Beat2", [](BattleManager& battleManager) {});
Skill Beat3("Beat3", [](BattleManager& battleManager) {});
Skill Beat4("Beat4", [](BattleManager& battleManager) {});