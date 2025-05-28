#ifndef BATTLE_PLAN_H
#define BATTLE_PLAN_H

typedef struct {
	int battle_id;               // Unique battle ID
	char name[100];              // Descriptive name of the battle plan
	char target_coordinates[200]; // Target coordinates or zones list
	int priority_level;          // Priority level (Low, Medium, High)
	int required_roles[10];      // Roster of required roles (array of CyborgRole enums)
	int assigned_cyborg_ids[50]; // Dynamic list of assigned cyborg IDs
	char status[20];            // Status (Scheduled, InProgress, Won, Lost)

} BattlePlan;

#endif // !BATTLE_PLAN_H
