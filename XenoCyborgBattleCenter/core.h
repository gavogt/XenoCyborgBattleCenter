#ifndef CORE_H
#define CORE_H

// initialize dynamic arrays
void init_fleet();
void init_battles();

// add cyborgs and battle plans, expanding storage as needed
void add_battle_plan();

// assign cyborgs to battles, checking role compatibility and avoiding duplicates
void assign_cyborg_to_battle();

// list cyborgs and battles, printing aligned columns
void list_cyborgs();
void list_battles();

// Menu Switch
bool menu_switch(int choice);

#endif // !CORE_H
