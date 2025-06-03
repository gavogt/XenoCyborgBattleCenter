#include "battle_plan.h"
#include "xeno_cyborg.h"
#include "core.h"
#include <stdlib.h>
#include "ui.h"

int plan_count = 0;
BattlePlan plans[MAX_PLANS];

bool menu_switch(int choice) {
	switch (choice) {
	case 1:
		add_cyborg();
		break;
	case 2:
		add_battle_plan();
		break;
	case 3:
		assign_cyborg_to_battle();
		break;
	case 4:
		list_battles();
		break;
	case 5:
		launch_battle_simulation();
		break;
	case 6:
		generate_after_action_report();
		break;
	case 7:
		save_and_exit();
		break;
	case 8:
		exit_without_saving();
		break;
	default:
		puts("Invalid choice. Please try again.");
	}
}

void assign_cyborg_to_battle() {
	char buf[32];
	int pid, cid;

	printf("Enter battle plan ID: ");
	if (!read_line(buf, sizeof buf)) return;
	buf[sizeof(buf) - 1] = '\0';
	pid = atoi(buf);

	printf("Enter cyborg ID to assign: ");
	if (!read_line(buf, sizeof buf)) return;
	cid = atoi(buf);

	for (int i = 0; i < plan_count; i++) {
		if (plans[i].id == pid)
		{
			if (plans[i].num_assigned >= MAX_ASSIGNED) {
				puts("Maximum number of cyborgs assigned to this plan reached.");
				return;
			}

			plans[i].assigned[plans[i].num_assigned++] = cid;
			printf("Assigned cyborg ID %d to battle plan ID %d\n", cid, pid);
			return;

		}
	}
	puts("Battle plan %d not found.", pid);
}

void list_battles() {
	if (plan_count == 0) {
		puts("No battle plans available.");
		return;
	}

	// Print header
	printf("%-10s %-20s %-15s %-10s %-10s %-10s\n", "ID", "Name", "Priority", "Status", "Assigned", "Roles");
	for (int i = 0; i < plan_count; i++) {
		BattlePlan* bp = &plans[i];
		printf("%3d | %-26s | %2d | %11s\n",
			bp->id, bp->name, bp->priority, battle_status_to_string(bp->status));

	}
	printf("\n");
}

void outcome_probability(int win_chance, int roll){
	printf("Outcome probability: %d%% (rolled %d)\n", win_chance, roll);
}


void  launch_battle_simulation() {
	if (plan_count == 0) {
		puts("No battle plans available to simulate.");
		return;
	}

	srand((unsigned int)time(NULL)); // Seed random number generator

	puts("Launching battle simulations...");

	for (int i = 0; i < plan_count; i++)
	{
		BattlePlan* bp = &plans[i];

		if (bp->status != SCHEDULED) {
			printf("Skipping battle plan %d (%s) - already %s in progress or completed.\n", bp->id, bp->name, battle_status_to_string(bp->status));
			continue;
		}

		bp->status = IN_PROGRESS;

		printf("Simulating battle plan %d (%s) with cyborg #%d assigned...\n", bp->id, bp->name, bp->num_assigned);

		int win_chance = bp->num_assigned * 10; // Each cyborg contributes 10% chance to win
		if (win_chance > 90) win_chance = 90;

		int roll = rand() % 100; // Random roll between 0 and 99
		if (roll < win_chance) {
			bp->status = WON;
			printf("Battle plan %d (%s) won!\n", bp->id, bp->name, battle_status_to_string(bp->status));
			outcome_probability(win_chance, roll);
		}
		else {
			bp->status = LOST;
			printf("Battle plan %d (%s) lost.\n", bp->id, bp->name, battle_status_to_string(bp->status));
			outcome_probability(win_chance, roll);
		}
	}
	printf("All battle simulations completed.\n");
}

void generate_after_action_report() {
	if(plan_count == 0)
	{
		puts("No battle plans available to generate report.");
		return;
	}

	puts("Generating after-action report...");

	printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Status", "Assigned Cyborgs");
	printf("--------------------------------------------------\n");

	for(int i = 0; i< plan_count; i++){
		BattlePlan* bp = &plans[i];
		printf("%-5d %-20s %-10s %d\n", bp->id, bp->name, battle_status_to_string(bp->status), bp->num_assigned);

	}

	printf("After-action report generated successfully.\n");

}

void save_and_exit() {

	puts("Saving data and exiting...");
	exit(EXIT_SUCCESS);
}

void exit_without_saving() {
	puts("Exiting without saving...");
	exit(EXIT_SUCCESS);
}