void MenuSwitch(int choice) {
	switch (choice) {
	case 1:
		//add_cyborg();
		break;
	case 2:
		//add_battle_plan();
		break;
	case 3:
		//assign_cyborg_to_battle();
		break;
	case 4:
		//list_battles();
		break;
	case 5:
		//launch_battle_simulation();
		break;
	case 6:
		//generate_after_action_report();
		break;
	case 7:
		//save_and_exit();
		break;
	case 8:
		//exit_without_saving();
		break;
	default:
		puts("Invalid choice. Please try again.");
	}
}