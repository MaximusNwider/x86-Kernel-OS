#ifndef DYNAMIC_STACK_H_
#define DYNAMIC_STACK_H_

typedef struct elem {

    char * data;
    int size;

}
elem_t;

typedef struct _stack {

    int index;
    int num_el;
    char * data;

}
stack_t;

extern void push(stack_t * s,const char * data);
extern void pop(stack_t * s,const char * data);
extern void display(const stack_t * s);
extern _Bool check_empty(const stack_t * s);
extern int check_size(const stack_t * s);
extern _Bool swap_elem(stack_t * s, elem_t * p0, elem_t * p1);

#endif // DYNAMIC_STACK_H_
