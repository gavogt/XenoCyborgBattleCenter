#ifndef CORE_H
#define CORE_H

// initialize dynamic arrays
void init_fleet();
void init_battles();

// assign cyborgs to battles, checking role compatibility and avoiding duplicates
void assign_cyborg_to_battle();
void launch_battle_simulation();

// list cyborgs and battles, printing aligned columns
void list_cyborgs();
void list_battles();

void generate_after_action_report();

// Menu Switch
bool menu_switch(int choice);

#endif // !CORE_H
