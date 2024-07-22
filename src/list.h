#ifndef __LIST_H
#define __LIST_H

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef struct {
    node_t *nodes;
    node_t *tail;
    int size;
} llist_t;

llist_t *init_list(void);
node_t *init_node(int value);
void push(llist_t *list, int value);
int pop(llist_t *list);
void print_list(llist_t *list);

#endif // __LIST_H

