#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool pushStack(Stack* s, int value) {
    if (s->top == MAX - 1) return false;
    s->data[++(s->top)] = value;
    return true;
}

bool popStack(Stack* s, int *value) {
    if (s->top == -1) return false;
    *value = s->data[(s->top)--];
    return true;
}

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

bool pushQueue(Queue* q, int value) {
    if (q->rear == MAX) return false;
    q->data[q->rear++] = value;
    return true;
}

bool popQueue(Queue* q, int *value) {
    if (q->front == q->rear) return false;
    *value = q->data[q->front++];
    return true;
}

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

void initPriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
}

bool pushPriorityQueue(PriorityQueue* pq, int value) {
    if (pq->size == MAX) return false;
    pq->data[pq->size++] = value;
    return true;
}

bool popPriorityQueue(PriorityQueue* pq, int *value) {
    if (pq->size == 0) return false;

    int maxIdx = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] > pq->data[maxIdx]) {
            maxIdx = i;
        }
    }

    *value = pq->data[maxIdx];
    
    pq->data[maxIdx] = pq->data[--(pq->size)];
    return true;
}

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        Stack stack;
        Queue queue;
        PriorityQueue pq;
        
        initStack(&stack);
        initQueue(&queue);
        initPriorityQueue(&pq);

        bool is_stack = true, is_queue = true, is_pq = true;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                if (!pushStack(&stack, x)) is_stack = false;
                if (!pushQueue(&queue, x)) is_queue = false;
                if (!pushPriorityQueue(&pq, x)) is_pq = false;
            } else if (op == 2) {
                int value;

                if (!popStack(&stack, &value) || value != x) is_stack = false;
                if (!popQueue(&queue, &value) || value != x) is_queue = false;
                if (!popPriorityQueue(&pq, &value) || value != x) is_pq = false;
            }
        }

        if (is_stack && !is_queue && !is_pq) {
            printf("stack\n");
        } else if (!is_stack && is_queue && !is_pq) {
            printf("queue\n");
        } else if (!is_stack && !is_queue && is_pq) {
            printf("priority queue\n");
        } else if (!is_stack && !is_queue && !is_pq) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }

    return 0;
}
