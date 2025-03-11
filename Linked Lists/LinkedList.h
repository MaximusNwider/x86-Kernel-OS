#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>

#include <stdlib.h>

typedef struct node {
    char data;
    struct node * next;
}
node_t;

typedef struct list {
    node_t * head;
}
list_t;

extern node_t * createNode(char data);
extern void insert(list_t * l, char data);
extern void print(list_t * l);
extern void freeList(list_t * l);
extern int list_size(list_t * l);
extern node_t find_node(list_t * l, char data);

#endif /* LINKEDLIST_H_ */
