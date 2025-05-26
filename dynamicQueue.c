#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    int data;
    struct queueNode *next;
} *front = NULL, *rear = NULL;

typedef struct queueNode qNode;

void enqueue() {
    qNode *newNode;
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    newNode = (qNode *)malloc(sizeof(qNode));
    if (newNode == NULL) {
        printf("Memory not available!!!");
    } else {
        newNode->data = val;
        newNode->next = NULL;
        if (front == NULL && rear == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        printf("\nElement is inserted in the queue.");
    }
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("\nQueue is empty");
    } else {
        qNode *temp = front;
        printf("\nElement %d is deleted from the queue", front->data);
        if (front == rear) {
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
        }
        free(temp);
    }
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty");
    } else {
        qNode *temp = front;
        printf("\nElements are: ");
        while (temp != NULL) {
            printf("%d => ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int ch;
    while (1) {
        printf("\nPress 1: Enqueue");
        printf("\nPress 2: Dequeue");
        printf("\nPress 3: Display");
        printf("\nPress 4: Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice entered...");
        }
    }
    return 0;
}
