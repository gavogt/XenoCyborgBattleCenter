#ifndef XENO_CYBORG_H
#define XENO_CYBORG_H

typedef enum { SCOUT, HEAVY_GUNNER, ENGINEER, MEDIC, DRONE_OPERATOR, FIELD_COMMANDER, DEMOLITION, PSI_OPERATIVE } CyborgRole;

typedef struct {
	int id;                     // Unique identifier for the cyborg
	char name[50];             // Name of the cyborg
	CyborgRole role;           // Role of the cyborg
	int health;                // Health points of the cyborg
	int attack_power;          // Attack power of the cyborg
	int defense_power;         // Defense power of the cyborg
	int speed;                 // Speed of the cyborg
} AlienCyborg;;

#endif // !XENO_CYBORG_H
