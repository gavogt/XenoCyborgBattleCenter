#ifndef BATTLE_PLAN_H
#define BATTLE_PLAN_H

#define MAX_ASSIGNED 10

typedef enum { SCHEDULED, IN_PROGRESS, WON, LOST } BattleStatus;

typedef struct {
	int id;
	char name[32];
	int assigned[MAX_ASSIGNED];
	int num_assigned; // Number of cyborgs assigned to this plan
	BattleStatus status;

} BattlePlan;

#endif // !BATTLE_PLAN_H
