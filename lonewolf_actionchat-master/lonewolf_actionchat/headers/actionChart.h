/* main.c 
 * ------
 * By ChinaskiJr - April 2018
 * 
 * role : contains headers of actionchart.c
 *
 */

#ifndef DEF_ACTIONCHART
#define DEF_ACTIONCHART

typedef struct Personnage Personnage;
struct Personnage {
    int endurance;
    int currentEndurance;
    int combatSkill;
    int currentCombatSkill;
    int gold;
    int meal;
    int weapon1;
    int weapon2;
    int weaponSkill;

    int disciplines[20];
    char backpack[200];
    char specialItems[200];
};

typedef struct Backpack BackpackItem;
struct BackpackItem {
    int endurModBackpack;
    int combSkillModBackpack;
    char name[];
};

typedef struct SpecialItem SpecialItem;
struct SpecialItem {
    int endurModSpecIt;
    int CombSkillModSpecIt;
    char name[];
};
void actionChart(WINDOW *actionChartWindow);

#endif