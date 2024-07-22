#include <stdio.h>
#include "list.h"

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

    int popped_value = pop(list);
    printf("popped value: %d\n", popped_value);
    print_list(list);

    push(list, 99);
    printf("values of list:\n");
    print_list(list);

    return 0;
}

