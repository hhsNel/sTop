size_t render_element(struct dspelement *menu, size_t i, size_t menu_size, size_t w, size_t h, size_t sw, size_t *prev_y);
size_t render_plaintext(size_t sx, size_t sy, size_t ex, size_t ey, char *text);
size_t render_button(size_t sx, size_t sy, size_t ex, size_t ey, char *btn_text);
size_t render_graph_over_time(size_t sx, size_t sy, size_t ex, size_t ey, void **mem, value_getter vget);
size_t render_divider(size_t sx, size_t sy, size_t ex, size_t ey, struct dspelement *menu, size_t i, size_t menu_size);
size_t render_render_value(size_t sx, size_t sy, size_t ex, size_t ey, value_getter vget);

size_t render_element(struct dspelement *menu, size_t i, size_t menu_size, size_t w, size_t h, size_t sw, size_t *prev_y) {
	size_t r;
	
	switch(menu[i].type) {
		case EL_PLAINTEXT:
			r = render_plaintext(sw, *prev_y, w, i * h / menu_size, (char *)menu[i].args.v);
			*prev_y = i * h / menu_size;
			break;
		case EL_MENU_BUTTON:
			r = render_button(sw, *prev_y, w, i * h / menu_size, (char *)menu[i].args.v);
			*prev_y = i * h / menu_size;
			break;
		case EL_GRAPH_OVER_TIME:
			r = render_graph_over_time(sw, *prev_y, w, i * h / menu_size, &menu[i].v, menu[i].func);
			*prev_y = i * h / menu_size;
			break;
		case EL_DIVIDER:
			r = render_divider(sw, prev_y, w, i * h / menu_size, menu, i, menu_size);
			break;
		case EL_VALUE:
			r = render_value(sw, *prev_y, w, i * h / menu_size, menu[i].func);
			*prev_y = i * h / menu_size;
			break;
	}
	return r;
}
