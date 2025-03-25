#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EL_PLAINTEXT 0
#define EL_MENU_BUTTON 1
#define EL_GRAPH_OVER_TIME 2
#define EL_DIVIDER 3
#define EL_VALUE 4

struct elargs {
	int i;
	void *v;
};

struct dspelement {
	int type;
	struct elargs args;
	void *func;

	char **prev_buff;
	char **buff;
	size_t w, h;
};

size_t count_element(struct dspelement *menu, size_t i);
static size_t count_def(struct dspelement *menu, size_t i);
static size_t count_div(struct dspelement *menu, size_t i);

size_t init_element(struct dspelement *menu, size_t i, size_t w, size_t h);
static size_t init_def(struct dspelement *menu, size_t i, size_t w, size_t h);
staitc size_t init_div(struct dspelement *menu, size_t i, size_t w, size_t h);

size_t render_element(struct dspelement *element, size_t i);
size_t render_def(struct dspelement *element, size_t i);
size_t render_div(struct dspelement *element, size_t i);

size_t buff_write_element(struct dspelement *element, size_t i, size_t x, size_t y, char **buff);
size_t buff_write_def(struct dspelement *element, size_t i, size_t x, size_t y, char **buff);
size_t buff_write_div(struct dspelement *element, size_t i, size_t x, size_t y, char **buff);

size_t out_delta_element(struct dspelement *element, size_t i, size_t x, size_t y);
size_t out_delta_def(struct dspelement *element, size_t i, size_t x, size_t y);
size_t out_delta_div(struct dspelement *element, size_t i, size_t x, size_t y);

void write_to_element(struct dspelement *element, size_t *x, size_t *y, char *str);
void unload_element(struct dspelement *element);
size_t element_render_differences(struct dspelement *menu, size_t i, size_t menu_size, size_t *y);
static size_t render_divider_diff(struct dspelement *menu, size_t i, size_t menu_size, size_t *y);
static void render_simple_diff(struct dspelement element, size_t x, size_t y);

void init_element(struct dspelement *element, size_t w, size_t h) {
	size_t i;

	element->w = w;
	element->h = h;
	element->prev_buff = (char **)malloc(sizeof(char *) * h);
	element->buff = (char **)malloc(sizeof(char *) * h);
	for(i = 0; i < h; ++i) {
		element->prev_buff[i] = (char *)malloc(sizeof(char) * w);
		element->buff[i] = (char *)malloc(sizeof(char) * w);
	}
}

void unload_element(struct dspelement *element) {
	size_t i;

	for(i = 0; i < element->h; ++i) {
		free(element->prev_buff[i]);
		free(element->buff[i]);
	}
	free(element->prev_buff);
	free(element->buff);
}

void write_to_element(struct dspelement *element, size_t *x, size_t *y, char *str) {
	while(*str) {
		element->buff[*y][*x] = *str;
		++(*x);
		*x %= element->w;
		if(x == 0) {
			++(*y);
			if(*y == element->h) return;
		}
		++str;
	}
}

size_t element_render_differences(struct dspelement *menu, size_t i, size_t menu_size, size_t *y) {
	size_t r;

	switch(menu[i].type) {
		case EL_DIVIDER:
			r = render_divider_diff(menu, i, menu_size, y);
			break;
		default:
			render_simple_diff(menu[i], 0, *y);
			r = 1;
			*y += menu[i].h;
			break;
	}
	return r;
}

static void render_simple_diff(struct dspelement element, size_t x, size_t y) {
	size_t i;

	for(i = 0; i < element.h; ++i) {
		if(strcmp(element.buff[i], element.prev_buff[i]) != 0) {
			strcpy(element.prev_buff[i], element.buff[i]);
			printf("\033[%d;%dH%s", y + i, x, element.buff[i]);
		}
	}
}

