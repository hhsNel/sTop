void render_menu(struct dspelement *menu, size_t menu_size, size_t w, size_t h);
void init_menu(struct dspelement *menu, size_t menu_size, size_t w, size_t h);
void unload_menu(struct dspelement *menu, size_t menu_size);

void render_menu(struct dspelement *menu, size_t menu_size, size_t w, size_t h) {
	size_t i;

	for(i = 0; i < menu_size;) {
		i += render_element(menu, i, menu_size);
	}
}

void init_menu(struct dspelement *menu, size_t menu_size, size_t w, size_t h) {
	size_t i;

	for(i = 0; i < menu_size; ++i) {
		init_element(menu + i, w, h);
	}
}

void unload_menu(struct dspelement *menu, size_t menu_size) {
	size_t i;
	for(i = 0; i < menu_size; ++i) {
		unload_element(menu + i);
	}
}

