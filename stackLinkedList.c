#include<stdio.h>
#include<stdlib.h>
struct stk{
    int data;
    struct stk* next;
}*TOP;

typedef struct stk node;

void push(){
    node *first;
    first = (node*)malloc(sizeof(node));
    
    if(first == NULL)
        printf("Memory unavailable");
    else{
        int val;
        printf("Enter the value: ");
        scanf("%d",&val);
        first->next = NULL;
        first->data = val;

        if(TOP == NULL){
            TOP = first;
            printf("\nElement is inserted");
        }
        else{
            first->next = TOP;
            TOP = first;
            printf("\nElement is inserted");
        }
    }
    
}
void pop(){
    node *temp = TOP;
    if(TOP == NULL)
        printf("\nUnderflow");
    else{
        if(TOP->next == NULL){
            free(temp);
            printf("\nElement is poped");
        }
        else{
            TOP = temp->next;
            free(temp);
            printf("\nElement is poped");
        }
    }
}
void display(){
    node *temp = TOP;

    if(TOP == NULL)
        printf("\nNo element is present");
    else{
        while(temp->next != NULL){
            printf("| %d |\n",temp->data);
            temp = temp->next;
        }
        printf("| %d |\n",temp->data);
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