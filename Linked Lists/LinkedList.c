#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

extern struct node * createNode(char data_in) {


  struct node * n = malloc(sizeof(node_t));

  n -> data = data_in;
  n -> next = NULL;

  return n;
}

extern void insert(struct list * l, char data) {

  struct node * newnode = createNode(data);

  newnode -> next = l -> head;
  l -> head = newnode;

}

extern void freelist(list_t * l) {
  node_t * current = l -> head;
  while (current != NULL) {
    node_t * next = current -> next;
    free(current);
    current = next;

  }

  l -> head = NULL;
}

extern void print(list_t * l) {

  node_t * current = l -> head;
  while (current != NULL) {
    printf("%c ", current -> data);
    current = current -> next;
  }

}

extern int list_size(list_t * l) {






}

extern node_t find_node(list_t * l, char data){





}
