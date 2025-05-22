#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int data;
    struct circularQueue * next;

}*front,*rear;

typedef struct circularQueue cQ;
void enqueue()
{
	cQ *last, *temp;
	int val;
	printf("Enter the value: ");
	scanf("%d", &val);
	last = (cQ *)malloc(sizeof(cQ));
	if (last == NULL)
	{
		printf("Memory not available!!!");
	}
	else
	{
		last->data = val;
		last->next = last;
        if(front == NULL && rear == NULL){
            front = last;
            rear = last;
            printf("\nElement is inserted in the queue.");
        }
        else{
			rear->next = last;
			last->next = front;
			rear = last;
		printf("\nElement is inserted in the queue.");
        }

    }
	
}

void dequeue(){
	if(front == NULL && rear == NULL) {
		printf("\nQueue is empty");
	} else {
		cQ *temp = front;
		if(front == rear) {
			printf("\nElement %d is deleted from the queue", front->data);
			free(front);
			front = NULL;
			rear = NULL;
		} else {
			printf("\nElement %d is deleted from the queue", front->data);
			front = front->next;
			rear->next = front;
			free(temp);
		}
	}
}

void display(){
	if(front == NULL && rear == NULL){
		printf("List is empty");
	}
	else{
		cQ* temp = front;
		printf("\nElements are: ");
		while(temp -> next != front){
			printf("%d =>",temp->data);
			temp = temp->next;
		}
		printf(" %d =>",temp->data);
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