#include <stdio.h>
#include <stdlib.h>
struct circularList
{
	int data;
	struct circularList *next;
} *start;
typedef struct circularList node;
void insertAtBegin()
{
	node *temp, *first;
	first = (node *)malloc(sizeof(node));
	int val;
	printf("Enter the value: ");
	scanf("%d", &val);
	if (first == NULL)
		printf("Memory is not available..\n");
	else
	{
		first->data = val;
		first->next = first;
	}
	if (start == NULL)
	{
		start = first;
		printf("Node is created instead of insertion\n");
	}
	else
	{
		temp = start;
		while (temp->next != start)
		{
			temp = temp->next;
		}
		temp->next = first;
		first->next = start;
		start = first;
		printf("%d is inserted at the first position\n", first->data);
	}
}
void insertlastCll()
{
	node *last, *temp;
	int val;
	printf("Enter the value: ");
	scanf("%d", &val);
	last = (node *)malloc(sizeof(node));
	if (last == NULL)
	{
		printf("Memory not available!!!");
	}
	else
	{
		last->data = val;
		last->next = last;
	}
	if (start == NULL)
	{
		start = last;
		printf("\nList is created instead of insertion...");
	}
	else
	{
		temp = start;
		while (temp->next != start)
		{
			temp = temp->next;
		}
		temp->next = last;
		last->next = start;
		printf("\n%d Node is inserted at last position succesfully..", last->data);
	}
}
void deletefirstCll()
{
	node *temp, *temp2;
	if (start == NULL)
	{
		printf("!!! List is Empty you cannot delete any node !!!");
	}
	else
	{
		temp = temp2 = start;
		while (temp->next != start)
		{
			temp = temp->next;
		}
		temp->next = start->next;
		start = start->next;
		printf("\n %d is deleted from the single linked list.");
		free(temp2);
	}
}

void deletelastCll()
{
	node *temp, *prev;
	if (start == NULL)
	{
		printf("\n !!!List is Empty, Deletion cannot be done. !!!");
	}
	else
	{
		temp = start;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = start;
		printf("\n%d is deleted from the Single Linked List.", temp->data);
		free(temp);
	}
}

void insertgivenpCll()
{
	node *givenp, *temp, *prev;
	int pos;
	int val;
	printf("Enter the value: ");
	scanf("%d", &val);
	printf("\nEnter the position after which you want to insert the node:");
	scanf("%d", &pos);
	givenp = (node *)malloc(sizeof(node));
	if (givenp == NULL)
	{
		printf("Memory not available!!!");
	}
	else
	{
		givenp->data = val;
		givenp->next = givenp;
	}
	if (start == NULL)
	{
		start = givenp;
		printf("\nList is created instead of insertion...");
	}
	else
	{
		int c = 0;
		temp = start;
		if (pos == 0)
		{
			while (temp->next != start)
				temp = temp->next;

			temp->next = givenp;
			givenp->next = start;
			start = givenp;
			printf("\n%d Node is inserted after given position succesfully..", givenp->data);
		}
		else
		{
			while (c != pos)
			{
				prev = temp;
				temp = temp->next;
				c++;
			}
			prev->next = givenp;
			givenp->next = temp;
			printf("\n%d Node is inserted after given position succesfully..", givenp->data);
		}
	}
}
void deletegivenpCll()
{
	node *temp, *prev;
	int pos;
	printf("\n Enter the position after which you want to delete the node:");
	scanf("%d", &pos);
	if (start == NULL)
	{
		printf("\n !!! List is empty, deletion cannot be done. !!!");
	}
	else
	{
		int c = 0;
		temp = start;
		while (c != pos)
		{
			prev = temp;
			temp = temp->next;
			c++;
		}
		prev->next = temp->next;
		printf("%d is deleted from the given position.", temp->data);
		free(temp);
	}
}
void display()
{
	node *temp;
	if (start == NULL)
		printf("Linked list is empty");
	temp = start;
	printf("Elements are:\n");
	while (temp->next != start)
	{
		printf("%d=> ", temp->data);
		temp = temp->next;
	}
	printf("%d=> ", temp->data);
}
int main()
{

	int ch;

	printf("\nPress 1: To insert at first in the CLL.");
	printf("\nPress 2: To insert at last in the CLL.");
	printf("\nPress 3: To delete at first in the CLL.");
	printf("\nPress 4: To delete at last in the CLL.");
	printf("\nPress 5: given position");
	printf("\nPress 6: To display the CLL.");
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
			insertlastCll();
			break;
		case 3:
			deletefirstCll();
			break;
		case 4:
			deletelastCll();
			break;
		case 5:
			insertgivenpCll();
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
