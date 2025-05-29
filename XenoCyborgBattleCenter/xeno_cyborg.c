#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "xeno_cyborg.h"
#include "util.h"

#define MAX_CYBORGS 20
#define NAME_LEN 64

static AlienCyborg fleet[MAX_CYBORGS];
static int cyborg_count = 0;

bool add_cyborg() {
	if (cyborg_count >= MAX_CYBORGS) {
		puts("Maximum number of cyborgs reached.");
		return;
	}

	AlienCyborg* cyborg = &fleet[cyborg_count];
	char buf[NAME_LEN];

	printf("Enter cyborg ID: ");
	if (!read_line(buf, sizeof buf)) return false;
	cyborg->id = atoi(buf);

	printf("Enter cyborg name: ");
	if (!read_line(cyborg->name, sizeof cyborg->name)) return;

	printf("Enter cyborg age: ");
	if (!read_line(buf, sizeof buf)) return false;
	cyborg->age = atoi(buf);

	printf("Enter cyborg role (0: SCOUT, 1: HEAVY_GUNNER, 2: ENGINEER, 3: MEDIC, 4: DRONE_OPERATOR, 5: FIELD_COMMANDER, 6: DEMOLITION, 7: PSI_OPERATIVE): ");
	if (!read_line(buf, sizeof buf)) return false;
	int choice = atoi(buf);
	if (choice < 0 || choice > 7) {
		puts("Invalid role choice. Please enter a number between 0 and 7.");
		cyborg->role = SCOUT; // Default to SCOUT if invalid
	}
	else {
		cyborg->role = (CyborgRole)choice;
	}

	printf("Added cyborg #%d: %s, age %d, role %d\n\n",
		cyborg->id, cyborg->name, cyborg->age, cyborg->role);

	return true;
}