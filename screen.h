#include <stdint.h>
#include <stdlib.h>
#include <sys/ioctl.h>

size_t screen_w = 0;
size_t screen_h = 0;

struct dspelement *current_menu;
size_t current_size;

void switch_menu(struct dspelement *new_menu, size_t new_size);
void render_differences();

void switch_menu(struct dspelement *new_menu, size_t new_size) {
	unload_menu(current_menu, current_size);
	init_menu(new_menu, new_size, screen_w, screen_h);
	current_menu = new_menu;
	current_size = new_size;
}

void render_differences() {
	size_t i, y;

	render_menu(current_menu, current_size, screen_w, screen_h);
	for(i = 0; i < current_size;) {
		i += element_render_differences(current_menu, i, current_size, &y);
	}
}

