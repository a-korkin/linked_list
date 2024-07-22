#include <stdlib.h>
#include <stdio.h>
#include "list.h"

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

int pop(llist_t *list) {
    int value = 0;
    if (list->tail) {
        value = list->tail->value;
        free(list->tail);
        list->tail = NULL;
        list->size--;
    }
    return value;
}

void print_list(llist_t *list) {
    node_t *node = list->nodes;
    printf("list size: %d\n", list->size);
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%d: value of node --> %d\n", i, node->value);
        node = node->next;
    }
}

