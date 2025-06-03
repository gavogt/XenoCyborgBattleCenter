/*
Assignment: AlienCyborg2 CLI Battle Center (Visual Studio 2022)

Objective:
  Build a menu-driven C application that manages Alien Cyborgs and their Battle Plans. Start with basic operations—adding, listing, assigning—and progressively layer in file I/O, plugins, threading, logging, and tests. This mirrors how real software grows from a small prototype into an “enterprise‐style” system without overwhelming you up front.

Requirements & Key Tasks:

1. Project Organization & Build System
   • Use Visual Studio 2022 (CMake or native solution).
   • Create folders:
     – src/       (all source .c/.h files)
     – tests/     (unit test files)
     – plugins/   (sample DLL extensions)
     – data/      (sample CSV/JSON files)
   • Configure your project so **Ctrl+Shift+B** builds the main app, plugins, and runs unit tests automatically.

2. Data Model
   • In xeno_cyborg.h, define an enum for roles (e.g. SCOUT, PSI_OPERATIVE, ENGINEER, etc.) and a struct AlienCyborg (ID, name, age, role, plus any role-specific stats).
   • In battle_plan.h, define a struct BattlePlan (unique ID, name, list of targets, priority, required roles, dynamic list of assigned cyborg IDs, status).

3. Core API (src/core.c / core.h)
   • Write functions to:
     – Initialize and grow dynamic arrays for cyborgs and battle plans.
     – Add a new cyborg or battle plan, expanding storage as needed.
     – Assign an existing cyborg (by ID) to a battle plan, checking for role compatibility and avoiding duplicates.
     – List all cyborgs or all battle plans in aligned columns.
     – Clean up (free) all allocated memory.

4. File I/O (src/io.c / io.h)
   • Support three modes—CSV text, binary, and JSON—chosen by a command-line flag.
   • Load and save both cyborgs and battle plans in the selected format.
   • If a file is missing, corrupted, or invalid JSON, log a warning and proceed with empty data.

5. Interactive Menu & CLI Flags (src/main.c)
   • Present a loop with exactly these options:
     1) Register new cyborg
     2) Create new battle plan
     3) Assign cyborgs to battle
     4) List battle plans
     5) Launch battle simulation
     6) Generate after-action report
     7) Save & Exit
     8) Exit without saving
   • Parse startup flags (e.g. --mode, --threads, --plugins, --verbose, --help). Use a simple parser or getopt.

6. Simulation & Concurrency (src/simulation.c / simulation.h)
   • Begin with a single‐threaded simulation: for each “Scheduled” battle, mark it “InProgress,” roll a random chance (e.g. 10% per assigned cyborg, capped at 90%), then mark “Won” or “Lost.”
   • Later (optional), accept a thread count and divide battles among threads so they run in parallel, then collect and summarize results back in the main thread.

7. Plugin System (src/plugin.c / plugin.h)
   • Define a minimal plugin interface so external DLLs can register custom battle behaviors.
   • On startup, look in plugins/ for DLLs, load each one, and call a known initialization function.
   • Provide a single sample plugin that demonstrates extending battle logic (e.g. a “Recon” plugin that boosts certain plans).

8. Logging & Error Handling (src/utils.c / utils.h)
   • Create a simple logger with levels INFO, DEBUG, and ERROR.
   • Write messages to console and a log file. Use a --verbose flag to enable DEBUG.
   • After every memory allocation, file operation, or thread call, check for failure and log an ERROR if needed.

9. Automated Tests & CI
   • In tests/, write a handful of unit tests (using assert or a small C framework) for:
     – Adding cyborgs and plans
     – Assignment logic
     – File I/O routines
     – Simulation outcomes
   • Configure your project (CMake or VS) so Test Explorer or `ctest` runs these tests on each build.
   • Supply a GitHub Actions workflow that builds with VS2022, runs tests, and checks for memory leaks (e.g. using Dr. Memory on Windows).

10. Cleanup & Shutdown
   • Ensure every dynamic array is freed, every thread is joined, and all loaded DLLs are unloaded on exit.
   • Implement “Exit without saving” so it skips file writes but still frees memory cleanly.

11. Documentation
   • At the top of each .c file, include author, date, and a one-line summary.
   • Comment each public function with its purpose and parameters (Doxygen-style).
   • Provide a README.md that explains:
     – Project overview and folder structure
     – Build & run instructions in VS2022 (or via CMake)
     – CLI flag usage
     – Plugin API details

Stretch Goals (Optional):
   • Add a basic TCP server so commands can come remotely (thread-safe).
   • Encrypt binary files with a simple AES library on save, decrypt on load.
   • Create a minimal GUI dashboard using Windows Console APIs or WinForms.

*/