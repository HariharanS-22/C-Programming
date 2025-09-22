#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *values;          // Acts like a array 
    int capacity;         // Total size 
    int size;             // Tracks the number of elements in stack
}Stack ;

Stack *create_stack(int capacity);
void delete_stack(Stack *stack);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool pop(Stack *stack, int *item);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *item);

int main(){
    Stack *stack = create_stack(5);
    if(is_empty(stack))
        printf("Stack is empty\n");
    
    push(stack,5);
    push(stack,7);
    printf("Stack size : %d\n",stack->size);

    push(stack,1);
    push(stack,8);
    push(stack,3);

    if(is_full(stack))
        printf("Stack is full\n");
    
    bool try_push = push(stack,0);
    if (try_push == false)
        printf("Push failed\n");
    
    int peek_value = 0;
    peek(stack, &peek_value);

    printf("Value at the top : %d\n",peek_value);

    int pop_value = 0;
    for(int i=0 ; i<stack->capacity ; i++){
        pop(stack, &pop_value);
        printf("Popped values : %d\n",pop_value);
    }

    bool try_pop = pop(stack,&pop_value);
    if (try_pop == false)
        printf("Pop failed\n");
    
    bool try_peek = peek(stack, &peek_value);
    if (try_peek == false)
        printf("Peek failed\n");

    delete_stack(stack);
    return 0;
}

Stack *create_stack(int capacity){
    if (capacity <= 0) 
        return NULL;
    
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)        //If malloc fails, it gives NULL 
        return NULL;
    
    stack->values = malloc(sizeof(int) * capacity);
    if(stack->values == NULL){
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void delete_stack(Stack *stack){
    free(stack->values);
    free(stack);
}

bool is_full(Stack *stack){
    return stack->capacity == stack->size;
}

bool is_empty(Stack *stack){
    return stack->size == 0;
}

bool push(Stack *stack, int item){
    if(is_full(stack))
        return false;

    stack->values[stack->size] = item;
    stack->size++;

    return true;
}

bool peek(Stack *stack, int *item){
    if(is_empty(stack))
        return false;

    *item = stack->values[stack->size - 1];
    return true;
    
}

bool pop(Stack *stack, int *item){
    if (is_empty(stack))
        return false;
    
    stack->size--;
    *item = stack->values[stack->size];

    return true;
}