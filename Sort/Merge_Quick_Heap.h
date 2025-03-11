#include <stdio.h>
#include <stdlib.h>

typedef struct ele {

    char * data;
    int size;

}
ele_t;

typedef struct stack {

    int index;
    int num_el;
    char * data;

}
Stack_t;

void push(Stack_t * s, char * data) {

    s -> index = s -> index + 1;


    ele_t * elementptr = (ele_t * ) calloc(1, sizeof(char));

    elementptr -> data = data;
    *(s -> data + s -> index) = elementptr -> data;

}
void pop(Stack_t * s, char *data) {



}

void display(Stack_t * s) {

    for (int i = 0; i < s -> index; i++) {
        printf("%c", *((s -> data + s -> index) - i * sizeof(char)));

    }

}

int main(void) {

    Stack_t * s = {
        NULL
    };

    char in ;

    while (scanf("%c", & in)) {
        if (in == 'q') {
            break;
        }

        push( & s, in);
    }

    display( & s);

    return 0;
}
