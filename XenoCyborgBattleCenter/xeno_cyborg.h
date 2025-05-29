#ifndef XENO_CYBORG_H
#define XENO_CYBORG_H

#include <stdbool.h>

typedef enum { SCOUT, HEAVY_GUNNER, ENGINEER, MEDIC, DRONE_OPERATOR, FIELD_COMMANDER, DEMOLITION, PSI_OPERATIVE } CyborgRole;

typedef struct {
	int id;                     // Unique identifier for the cyborg
	char name[50];             // Name of the cyborg
	int age;				  // Age of the cyborg
	CyborgRole role;           // Role of the cyborg
} AlienCyborg;;


bool add_cyborg(); // Function to add a new cyborg

#endif // !XENO_CYBORG_H
