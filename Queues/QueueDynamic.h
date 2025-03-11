#ifndef DYNAMIC_QUEUE_H_
#define DYNAMIC_QUEUE_H_

typedef struct ele {

    char * data;


}
ele_t;

typedef struct queue {

    int index;
    int num_el;
    char * data;

}
queue_t;

extern void push(stack_t * s,const char * data);
extern void pop(stack_t * s,const char * data);
extern void display(const stack_t * s);
extern _Bool check_empty(const stack_t * s);
extern int check_size(const stack_t * s);
extern _Bool swap_elem(stack_t * s, elem_t * p0, elem_t * p1);

#endif // DYNAMIC_QUEUE_H_