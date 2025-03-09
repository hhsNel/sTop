size_t render_element(struct dspelement *menu, size_t i, size_t menu_size);
size_t render_plaintext(struct dspelement *menu, size_t i, size_t menu_size);
size_t render_button(struct dspelement *menu, size_t i, size_t menu_size);
size_t render_graph_over_time(struct dspelement *menu, size_t i, size_t menu_size);
size_t render_divider(struct dspelement *menu, size_t i, size_t menu_size);
size_t render_value(struct dspelement *menu, size_t i, size_t menu_size);

size_t render_element(struct dspelement *menu, size_t i, size_t menu_size) {
	size_t r;
	
	switch(menu[i].type) {
		case EL_PLAINTEXT:
			r = render_plaintext(menu, i, menu_size);
			break;
		case EL_MENU_BUTTON:
			r = render_button(menu, i, menu_size);
			break;
		case EL_GRAPH_OVER_TIME:
			r = render_graph_over_time(menu, i, menu_size);
			break;
		case EL_DIVIDER:
			r = render_divider(menu, i, menu_size);
			break;
		case EL_VALUE:
			r = render_value(menu, i, menu_size);
			break;
	}
	return r;
}
