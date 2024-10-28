#include "list.h"

struct list *create_new_list(void) {
    struct list *new_list = (struct list*) malloc(sizeof(struct list));
    new_list->first       = NULL;
    new_list->last        = NULL;
    return new_list;
}

void list_push(struct list *list, int data) {
    if (list == NULL)
        return;
        
    if (list_count(list) == 0) {
        handle_first_push(list, data);
        return;
    }

    list->last->next            = (struct list_node*) malloc(sizeof(struct list_node));
    list->last->next->data      = data;
    list->last->next->previous  = list->last;
    list->last                  = list->last->next;
}

void list_pop(struct list *list, const int matching) {
    if (list == NULL || list->first == NULL)
        return;

    struct list_node *node_ptr          = list->first;
    struct list_node *next_node         = node_ptr->next;
    struct list_node *previous_node     = node_ptr->previous;
    while (1) {
        if (node_ptr->data == matching) {
            if (list_count(list) == 1) {
                free(node_ptr);
                list->first = NULL;
                list->last  = NULL;    
                break;
            }

            free(node_ptr);
            if (node_ptr == list->first) {
                next_node->previous = NULL;
                list->first = next_node;
                list->first->previous = NULL;
                break;

            } else if (node_ptr == list->last) {
                previous_node->next = NULL;
                list->last = previous_node;
                break;
            } else {
                previous_node->next = next_node;
                next_node->previous = previous_node;
                break;
            }
        } else if (node_ptr->data != matching && node_ptr == list->last) {
            node_ptr        = NULL;
            next_node       = NULL;
            previous_node   = NULL;
            break;
        } else {
            node_ptr        = node_ptr->next;
            next_node       = node_ptr->next;
            previous_node   = node_ptr->previous;
        }
    }
    
}

void delete_list(struct list *list) {
    if (list != NULL) {
        struct list_node *node_ptr  = list->first;
        struct list_node *next_node = NULL;
        while (node_ptr != NULL) {
            next_node = node_ptr->next;
            free(node_ptr);
            node_ptr = next_node;
        }
        free(list);
    }
}

void list_print(const struct list *list) {
    if (list == NULL || list_count(list) == 0)
        return;

    struct list_node *node_ptr = list->first;
    while (node_ptr != NULL) {
        printf("[ %d ] ----> ", node_ptr->data);
        node_ptr = node_ptr->next;
    }
    printf("\n Head = %d \n Tail = %d\n", list->first->data, list->last->data);

}

void handle_first_push(struct list *list, int data) {
    if (list != NULL) {
        list->first = (struct list_node *) malloc(sizeof(struct list_node));
        list->first->data = data;
        list->first->next = NULL;
        list->last = list->first;
        list->first->previous = list->last;
    }
}

size_t list_count(const struct list *list) {
    if (list != NULL) {
        size_t count = 0;
        struct list_node *count_ptr = list->first;
        while (count_ptr != NULL) {
            count++;
            count_ptr = count_ptr->next;
        }
        return count;
    }
    printf("MASON, THE NUMBERS\n");
    return -1;
}
