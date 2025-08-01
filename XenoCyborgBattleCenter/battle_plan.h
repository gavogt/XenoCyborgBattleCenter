#ifndef BATTLE_PLAN_H
#define BATTLE_PLAN_H

#define MAX_ASSIGNED 10
#define MAX_PLANS 10

extern int plan_count;

typedef enum { SCHEDULED, IN_PROGRESS, WON, LOST } BattleStatus;
typedef enum { LOW, MEDIUM, HIGH } PriorityLevel;

typedef struct {
	int id;
	char name[32];
	int assigned[MAX_ASSIGNED];
	int num_assigned; // Number of cyborgs assigned to this plan
	PriorityLevel priority;
	BattleStatus status;

} BattlePlan;

const char* battle_status_to_string(BattleStatus status);
void add_battle_plan();

extern BattlePlan plans[MAX_PLANS];

#endif // !BATTLE_PLAN_H
