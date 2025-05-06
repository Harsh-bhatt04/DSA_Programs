#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node* next;
}*start;
typedef struct node node;

struct node* createNode(int coeff, int exp){
    node *new_node = (node*)malloc(sizeof(node));

    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;

    return new_node;
}

void insertNode(node **poly, int coeff , int exp){
    node *temp = *poly;
    node * addNode = createNode(coeff,exp);

    if(*poly == NULL){
        *poly = addNode;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = addNode;
    }
}

struct node* addPoly(node *poly1, node* poly2){
    node *result = NULL;
    node **tail = &result; // can be commented out
    while(poly1 != NULL && poly2 != NULL){
        if(poly1->exp == poly2->exp){
            insertNode(tail,poly1->coeff + poly2->coeff, poly1->exp);//-
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        }
        else if(poly1->exp > poly2->exp){//
            insertNode(tail, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else{
            insertNode(tail, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        tail = &((*tail)->next);//no need to do the traversal 
    }
   

    while(poly1 != NULL){
        insertNode(tail,poly1->coeff,poly1->exp);
        poly1 = poly1->next;
        tail = &((*tail)->next);
    }

    while(poly2 != NULL){
        insertNode(tail,poly2->coeff,poly2->exp);
        poly2 = poly2->next;
        tail = &((*tail)->next);
    }
    return result;
}

struct node* subPoly(node *poly1, node* poly2){
    node *result = NULL;
    node **tail = &result; // can be commented out
    while(poly1 != NULL && poly2 != NULL){
        if(poly1->exp == poly2->exp){
            insertNode(tail,poly1->coeff - poly2->coeff, poly1->exp);//-
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        }
        else if(poly1->exp > poly2->exp){//
            insertNode(tail, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else{
            insertNode(tail, -(poly2->coeff), poly2->exp);
            poly2 = poly2->next;
        }
        tail = &((*tail)->next);//no need to do the traversal 
    }
   

    while(poly1 != NULL){
        insertNode(tail,poly1->coeff,poly1->exp);
        poly1 = poly1->next;
        tail = &((*tail)->next);
    }

    while(poly2 != NULL){
        insertNode(tail,poly2->coeff,poly2->exp);
        poly2 = poly2->next;
        tail = &((*tail)->next);
    }
    return result;
}
void print(node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    node* current = poly;
    
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    
    printf("\n");
}
struct node* multPoly(node *poly1,node *poly2){
    
}
int main() {
    node* poly1 = NULL;
    insertNode(&poly1, 5, 4);
    insertNode(&poly1, 3, 2);
    insertNode(&poly1, 1, 0);


    node* poly2 = NULL;
    insertNode(&poly2, 4, 4);
    insertNode(&poly2, 2, 2);
    insertNode(&poly2, 1, 1);

    printf("First polynomial: ");
    print(poly1);
    printf("Second polynomial: ");
    print(poly2);

    node *result1 = addPoly(poly1,poly2);
    printf("The addition is : ");
    print(result1);

    node *result2 = subPoly(poly1,poly2);
    printf("The substraction is : ");
    print(result2);
    return 0;
}