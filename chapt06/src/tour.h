typedef struct _ISLAND island;
void display(island *start);

struct _ISLAND {
    char *name;
    char *opens;
    char *closes;
    struct _ISLAND *next;
};