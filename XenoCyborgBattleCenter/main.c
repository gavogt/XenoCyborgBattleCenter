#include "xeno_cyborg.h"
#include "core.h"
#include <stdbool.h>
#include "util.h"

int main() {
	WelcomeMessage();

	bool running = true;
	char buf[16];
	int choice = 0;

	while(running){
		puts("1. Add Cyborg");
		puts("2. Add Battle Plan");
		puts("3. Assign Cyborg to Battle Plan");
		puts("4. List Battle Plans");
		puts("5. Launch Battle Simulation");
		puts("6. Generate After Action Report");
		puts("7. Save and Exit");
		puts("8. Exit Without Saving");
		printf("Enter your choice: ");

		if(!read_line(buf, sizeof buf))
		{
			break;
		}

		choice = atoi(buf);

		running = menu_switch(choice);
	}

	return 0;
}