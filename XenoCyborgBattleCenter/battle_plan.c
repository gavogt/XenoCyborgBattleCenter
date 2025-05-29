#include <stdio.h>
#include <string.h>

#include "battle_plan.h"

#define MAX_PLANS 10

BattlePlan plans[MAX_PLANS];

int plan_count = 0;


void add_battle_plan() {
	if (plan_count >= MAX_PLANS) {
		puts("Maximum number of battle plans reached.");
		return;
	}

	BattlePlan* bp = &plans[plan_count];
	bp->num_assigned = 0;
	bp->status = SCHEDULED;

	printf("Enter battle plan ID:");
	if (scanf_s("%d", &bp->id) != 1)
	{
		fprintf(stderr, "Invalid input for battle plan ID.\n");
		while (getchar() != '\n'); // Clear input buffer
		return;
	}

	// consume leftover '\n' from scanf
	while (getchar() != '\n'); // Clear input buffer

	printf("Enter battle plan name: ");
	if (gets_s(bp->name, sizeof(bp->name)) == NULL) {
		fprintf(stderr, "Error reading battle plan name.\n");
		return;
	}

	bp->name[strcspn(bp->name, "\n")] = '\0'; // Strip newline if present

	printf("Created plan \"%s\" with ID %d", bp->name, bp->id);
}
