#include <stdio.h>
#include <stdlib.h>

#define linkedListInit(ll) linkedList ll;\
    linked_list_init(&ll)

struct LinkedList {
    void *item;
    struct LinkedList *next;

    void (*pfpush_front)(linkedList *, void *);
};

typedef struct LinkedList linkedList;

void fpush_front(linkedList *ll, void *item) {
    ll->item = item;
    ll->next = NULL;
}

void linked_list_init(linkedList *ll) {
    ll->pfpush_front = fpush_front;

    linkedList *head = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    head->item = NULL;
    head->next = NULL;
}