#include <stdio.h>
#include <stdlib.h>
struct doublyLinkedList
{
	int data;
	struct doublyLinkedList *next;
    struct doublyLinkedList *prev;
} *start;
typedef struct doublyLinkedList node;
int val;

void insertAtBegin(){
	node *begin;
	begin = (node*)malloc(sizeof(node));
	if(begin == NULL)
	printf("Memory not available\n");

	printf("Enter the value: ");
	scanf("%d",&val);
	begin->next = NULL;
	begin->prev = NULL;
	begin->data = val;
	if(start == NULL){
		start = begin;
		printf("List is created instead of insertion\n");
	}
	else{
		begin->next = start;
		start->prev = begin;
		start = begin;
		printf("Node is inserted at begin\n");
	}
}
void insertAtEnd(){
	node *end;
	end = (node*)malloc(sizeof(node));
	if(end == NULL)
		printf("Memory not available\n");

	printf("Enter the value: ");
	scanf("%d",&val);
	end->next = NULL;
	end->prev = NULL;
	end->data = val;
	if(start == NULL){
		start = end;
		printf("List is created instead of insertion\n");
	}
	else{
		if(start -> next == NULL){
			start->next = end;
			end->prev = start;
			printf("Node is inserted at the end\n");
		}
		else{
			node *temp = start;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = end;
			end->prev = temp;
			printf("Node is inserted at the end\n");

		}
	}
}
void insertGivenPos(){
	node *given;
	given = (node*)malloc(sizeof(node));
	if(given == NULL) {
		printf("Memory not available\n");
		return;
	}

	// Input the value to insert
	printf("Enter the value: ");
	scanf("%d", &val);
	int pos;
	printf("Enter the position where you want to insert the element: ");
	scanf("%d", &pos);
	given->next = NULL;
	given->prev = NULL;
	given->data = val;

	// If the list is empty, create the list with the new node
	if (start == NULL) {
		start = given;
		printf("List is created instead of insertion\n");
	} else {
		// If inserting at position 0, update start and handle pointers
		if (pos == 0) {
			given->next = start;
			start->prev = given;
			start = given;
			printf("Node is inserted at the given position\n");
		} else {
			// Traverse to the desired position
			node *temp = start;
			int c = 0;
			while (c < pos - 1 && temp->next != NULL) {
				temp = temp->next;
				c++;
			}
			// Insert the node at the position
			given->next = temp->next;
			if (temp->next != NULL) {
				temp->next->prev = given;
			}
			temp->next = given;
			given->prev = temp;
			printf("Node is inserted at the given position\n");
		}
	}

}
void deleteAtBegin(){
	if(start == NULL)
		printf("List is empty\n");
	
	node *temp = start;
	if(start->next == NULL){
		start = NULL;
		free(temp);
		printf("Node is deleted from starting\n");
	}
	else{
		start = start->next;
		temp->next->prev = NULL;
		free(temp);
		printf("Node is deleted from starting\n");
	}
}
void deleteAtEnd(){
	if(start == NULL)
		printf("List is empty\n");
	
	node *temp = start;
	if(start->next == NULL){
		start = NULL;
		free(temp);
		printf("Node is deleted from ending\n");
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->prev->next = NULL;
		free(temp);
		printf("Node is deleted from ending\n");
	}
}
void display(){
	node *temp;
	temp = start;
	if (start == NULL)
		printf("Linked list is empty");
	printf("Elements are:\n");
	while (temp != NULL)
	{
		printf("%d=> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
int main()
{
    int ch;

	printf("\nPress 1: To insert at first in the DLL.");
	printf("\nPress 2: To insert at last in the DLL.");
	printf("\nPress 3: To delete at first in the DLL.");
	printf("\nPress 4: To delete at last in the DLL.");
	printf("\nPress 5: given position");
	printf("\nPress 6: To display the DLL.");
	printf("\nPress 7: To exit from the menu.");
	printf("\nEnter your choice:");
	scanf("%d", &ch);

	while (ch != 0)
	{
		switch (ch)
		{
		case 1:
			insertAtBegin();
			break;
		case 2:
			insertAtEnd();
			break;
		case 3:
			deleteAtBegin();
			break;
		case 4:
			deleteAtEnd();
			break;
		case 5:
		    insertGivenPos();
			break;
		case 6:
			display();
			break;
		case 7:
			exit(0);
			//
		default:
			printf("\n!!!! Wrong Choince Entered!!!!");
		};
		main();
	}
}