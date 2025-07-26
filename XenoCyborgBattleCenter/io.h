#ifndef IO_H
#define IO_H

typedef enum {
	IO_MODE_CSV,
	IO_MODE_BINARY,
	IO_MODE_JSON
} IOMode;

// Call at startup
void io_load_all(IOMode mode);

// Call before exit
void io_save_all(IOMode mode);

#endif // !IO_H
