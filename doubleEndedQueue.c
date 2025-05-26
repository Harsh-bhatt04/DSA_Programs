#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insertFront(){
    int val;
    printf("\nEnter the value: ");
    scanf("%d",&val);

    if(front == 0 && rear == MAX - 1){
        printf("\nOverflow");
    }
    else{
        if(front == -1){
            front = 0;
            rear = 0;
            queue[front] = val;
            printf("\nElement is inserted");
        }
        else{
            front--;
            queue[front] = val;
            printf("\nElement is inserted");
        }
    }

}
void enqueue() {
    int val;
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &val);
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = val;
    printf("\nElement is inserted in the queue.");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nElement %d is deleted from the queue", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty");
        return;
    }
    printf("\nElements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d => ", queue[i]);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\nPress 1: Enqueue");
        printf("\nPress 2: Dequeue");
        printf("\nPress 3: front insertion");
        printf("\nPress 4: Display");
        printf("\nPress 5: Exit");
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
                insertFront();
                break;
            case 4:
                display(0);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice entered...");
        }
    }
    return 0;
}
