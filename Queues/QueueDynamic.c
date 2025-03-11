#include <stdio.h>
#include <stdlib.h>
#include "QueueDynamic.h"

void push(queue_t * s, char * data) {

    s -> index = s -> index + 1;


    ele_t * elementptr = (ele_t * ) calloc(1, sizeof(char*));

    elementptr -> data = data;
    *(s -> data + s -> index) = elementptr -> data;



}
void pop(queue_t * s, char *data) {



}

void display(queue_t * s) {
printf("----------\n");
printf("OUTPUT:\n");
    for (int i = 0; i < s -> index; i++) {
        printf("%c\n", *(++s -> data + i));

    }

}