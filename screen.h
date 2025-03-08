#include <stdint.h>
#include <stdlib.h>
#include <sys/ioctl.h>

size_t screen_w = 0;
size_t screen_h = 0;
char *output_buff;
void update_screen_dims();
static void regenerate_screen(size_t w, size_t h);

void update_screen_dims() {
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	if(w.ws_row != screen_h || w.ws_col != screen_w) {
		regenerate_screen(w.ws_col, w.ws_row);
	}
}
static void regenerate_screen(size_t w, size_t h) {
	
}
