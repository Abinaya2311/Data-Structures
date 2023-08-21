#include <stdio.h>
#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return (q->rear == MAX_SIZE - 1 && q->front == 0) || (q->rear == q->front - 1);
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow\n");
    } else {
        if (q->rear == -1) {
            q->front = 0;
            q->rear = 0;
        } else if (q->rear == MAX_SIZE - 1) {
            q->rear = 0;
        } else {
            q->rear++;
        }
        q->items[q->rear] = value;
        printf("%d enqueued\n", value);
    }
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1; // Return a sentinel value to indicate underflow
    } else {
        int value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else if (q->front == MAX_SIZE - 1) {
            q->front = 0;
        } else {
            q->front++;
        }
        return value;
    }
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        int i = q->front;
        printf("Queue: ");
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) {
                break;
            }
            if (i == MAX_SIZE - 1) {
                i = 0;
            } else {
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("%d dequeued\n", dequeue(&queue));

    display(&queue);

    return 0;
}

