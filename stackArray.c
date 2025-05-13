#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int TOP = -1;
int stk[MAX];

int isEmpty(int top){
    if(top == -1)
        return 1;
    else    
        return 0;
}
int isFull(int top){
    if(top == MAX-1)
        return 1;
    else    
        return 0;
}

void push(){
    int val;
    if(isFull(TOP)){
        printf("Stack is full\n");
    }
    else{
        printf("Enter the value:");
        scanf("%d",&val);
        stk[++TOP] = val;
        printf("Element is pushed successfully\n");
    }
}
void pop(){
    int val;
    if(isEmpty(TOP)){
        printf("Stack is Empty\n");
    }
    else{
        int val = stk[TOP];
        TOP -= 1;
        printf(" %d is poped successfully\n",val);
    }
}
void display() {
    if (isEmpty(TOP)) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = TOP; i >= 0; i--) {
            printf(" | %d |\n", stk[i]);
        }
    }
}
int main(){
    int ch;

    printf("1.) PUSH\n");
    printf("2.) POP\n");
    printf("3.) Display\n");
    printf("4.) Exit\n");
    printf("\nEnter your choice:");
	scanf("%d", &ch);

    while (ch != 0)
	{
		switch (ch)
		{
		case 1:
			push();
			break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4: 
            exit(0);
        default:
            printf("Wrong choice entered\n");
        }
        main();
    }
}