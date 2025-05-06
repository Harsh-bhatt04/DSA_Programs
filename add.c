#include<stdio.h>
#include<stdlib.h>
struct circularList{
    int data;
    struct circularList *next;
}*start;
int main(){
    struct circularList *temp;
    printf("temp %p\n",temp);
    printf("start %p\n",start);
    temp = (struct circularList *)malloc(sizeof(struct circularList));
    temp ->data = 6;
    temp ->next = NULL;
    printf("temp %p\n",&(temp));
    printf("temp %p\n",&(temp->data));
    printf("temp %p\n",&(temp->next));


}