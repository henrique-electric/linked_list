#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_INT_VALUE   0x0FFFFFFF


struct list_node {
    struct list_node *next, *previous;
    int data;
};


struct list {
    struct list_node *first, *last;
};

struct list* create_new_list(void);
void list_push(struct list* list, int data);
void list_pop(struct list* list, const int matching);
void delete_list(struct list *list);
void list_print(const struct list *list);
static void handle_first_push(struct list *list, int data);
size_t list_count(const struct list *list);