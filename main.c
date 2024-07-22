#include <stdio.h>
#include <stdlib.h>

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
void print_list(llist_t *list);

int main(void) {
    llist_t *list = init_list();
    int value;
    printf("Enter next value: ");
    while (scanf("%d", &value) == 1) {
        push(list, value);
        printf("Enter next value: ");
    }

    printf("values of list:\n");
    print_list(list);

    return 0;
}

llist_t *init_list(void) {
    llist_t *list = (llist_t *) malloc(sizeof(llist_t));
    if (!list) {
        fprintf(stderr, "ERROR allocating memory for list\n");
        exit(1);
    }
    list->nodes = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

node_t *init_node(int value) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    if (!node) {
        fprintf(stderr, "ERROR allocating memory for node\n");
        exit(1);
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void push(llist_t *list, int value) {
    node_t *node = init_node(value);
    if (!list->nodes) {
        list->nodes = node;
    }
    if (list->tail) {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

void print_list(llist_t *list) {
    node_t *node = list->nodes;
    printf("list size: %d\n", list->size);
    int i = 0;
    while (node) {
        printf("%d: value of node --> %d\n", i++, node->value);
        node = node->next;
    }
}
