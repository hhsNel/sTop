void render_menu(struct dspelement *menu, size_t menu_size, size_t w, size_t h);

void render_menu(struct dspelement *menu, size_t menu_size, size_t w, size_t h) {
	size_t i, this_y, prev_y = 0;

	for(i = 0; i < menu_size;) {
		this_y = i * h / menu_size;
		i += render_element(menu, i, menu_size, w, h, &prev_y);

		prev_y = this_y;
	}
}
