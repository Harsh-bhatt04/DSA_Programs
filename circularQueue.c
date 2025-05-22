#include <stdio.h>
#include <stdlib.h>
int queue[5];
int rear = -1;
int front = -1;

void enqueue()
{
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    if (front == (rear + 1) % 5)
    {
        printf("\nOverflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = val;
        printf("Element is inserted at the end");
    }
    else
    {
        rear = (rear + 1) % 5;
        queue[rear] = val;
        printf("\nElement is inserted");
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nUnderflow");
    }
    else if (front == rear)
    {
        printf("\nDeleted element: %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nDeleted element: %d", queue[front]);
        front = (front + 1) % 5;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue elements: ");
        int i = front;
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % 5;
        }
    }
}
int main()
{
    int ch;

    printf("\nPress 1: Enqueue");
    printf("\nPress 2: dequeue");
    printf("\nPress 3: Display");
    printf("\nPress 4: exit");
    printf("\nEnter the choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
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
    main();

    return 0;
}