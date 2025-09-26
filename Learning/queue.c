#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{               // Node ie each value
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;                    // First node 
    Node *tail;                    // Last node 
    int size;                      // Allocated size of queue
} Queue;

Queue *create_queue();
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int val);
int dequeue(Queue *queue, bool *status);
void delete_queue(Queue *queue);

int main(){
    Queue *queue = create_queue();

    if (is_empty(queue)) printf("Queue is empty\n");

    enqueue(queue,22);
    if (!is_empty(queue)) printf("Queue is not empty\n");
    
    enqueue(queue,14);
    enqueue(queue,2);
    printf("Current Queue Size : %d\n",queue->size);
    bool status = false;
    int value =0;

    value = peek(queue, &status);
    if (status) printf("Peek successful, the value : %d\n",value);

    value = dequeue(queue, &status);
    if (status) printf("Dequeue Successful, the value : %d\n", value);

    while(!is_empty(queue)){
        value = peek(queue, &status);
        if (status) printf("Peek successful, the value : %d\n",value);
        value = dequeue(queue, &status);
        if (status) printf("Dequeue Successful, the value : %d\n", value);
    }

    value = peek(queue, &status);
    if (!status) printf("Peek unsuccessful\n");
    value = dequeue(queue, &status);
    if (!status) printf("Dequeue unsuccessful\n");

    delete_queue(queue);

    return 0;
}

Queue *create_queue(){
    Queue *queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

bool is_empty(Queue *queue){
    return (queue->size == 0);
}

int peek(Queue *queue, bool *status){
    if (is_empty(queue)){
        *status = false;
        return NULL;
    }
    *status = true;
    return queue->head->value;

}
void enqueue(Queue *queue, int val){
    Node *newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;

    if (is_empty(queue)){        // Initial case when queue is created
        queue->head = newNode;
        queue->tail = newNode;
    }
    else{
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}

int dequeue(Queue *queue, bool *status){
    if (is_empty(queue)){
        *status = false;
        return NULL;
    }
    *status = true;
    int value = queue->head->value;
    //delete the head node
    Node *oldNode = queue->head;

    if(queue->size == 1){
        queue->head = NULL;
        queue->tail = NULL;
    }
    else{
        queue->head = queue->head->next;
    }

    free(oldNode);
    queue->size --;

    return value;

}
void delete_queue(Queue *queue){
    Node *current = queue->head;
    
    while(current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}