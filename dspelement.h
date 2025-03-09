#include <stdlib.h>

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

void init_element(struct dspelement *element, size_t w, size_t h);
void write_to_element(struct dspelement *element, size_t *x, size_t *y, char *str);

void init_element(struct dspelement *element, size_t w, size_t h) {
	element->w = w;
	element->h = h;
	element->prev_buff = (char **)malloc(sizeof(char *) * h);
	element->buff = (char **)malloc(sizeof(char *) * h);
	for(size_t i = 0; i < h; ++i) {
		element->prev_buff[i] = (char *)malloc(sizeof(char) * w);
		element->buff[i] = (char *)malloc(sizeof(char) * w);
	}
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

