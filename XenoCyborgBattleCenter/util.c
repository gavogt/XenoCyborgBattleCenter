#include <stdio.h> // for fgets, stdin
#include <string.h> // for strcspn
#include <stdbool.h> // for bool
#include <stddef.h> // for size_t

/*
@brief Read a line of text from STDIN

Reads up to len - 1 characters, null-terminates the string, 
and strips the newline character if present.

@param buf Pointer to a buffer that will be size len
@param len Size of the buffer, must be greater than 0
@return true on success of reading newline or false if EOF or error
*/
bool read_line(char* buf, size_t len) {
	if (!fgets(buf, len, stdin)) return false;
	// strip newline
	buf[strcspn(buf, "\n")] = '\0';
	return true;
}