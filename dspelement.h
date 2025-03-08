#define EL_PLAINTEXT 0
#define EL_MENU_BUTTON 1
#define EL_GRAPH_OVER_TIME 2
#define EL_DIVIDER 3
#define EL_VALUE 4

struct elargs {
	int i;
	void *v;
}

struct dspelement {
	int type;
	struct elargs args;
	void *func
}
