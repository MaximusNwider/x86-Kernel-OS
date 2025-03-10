#include <stdio.h>

#include <stdlib.h>

#include "Dynamic_Stack.h"



extern void push(stack_t * s, const char * data) {

    s -> index = s -> index + 1;

    elem_t * elementptr = (elem_t * ) calloc(1, sizeof(char));

    elementptr -> data = data;
    *(s -> data + (int )s -> index) = elementptr -> data;

}
extern void pop(stack_t * s, const char * data) {


}

extern void display(const stack_t * s) {

    for (int i = 0; i < s -> index; i++) {
        printf("%c", *((s -> data + s -> index) - i * sizeof(char)));

    }

}
extern _Bool check_empty(const stack_t * s) {

}
extern int check_size(const stack_t * s) {

}
extern _Bool swap_elem(stack_t * s, elem_t * p0, elem_t * p1) {

}
