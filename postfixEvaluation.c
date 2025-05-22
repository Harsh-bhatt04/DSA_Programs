#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct stk{
    int top;
    unsigned capacity;
    int* array;
};

struct stk* createStack(unsigned capacity){
    struct stk* stack = (struct stk*)malloc(sizeof(struct stk));

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
}

int isEmpty(struct stk* stack){return stack->top == -1;}

int pop(struct stk* stack){
    if(!(isEmpty(stack)))
        return stack->array[stack->top--];
}

void push(struct stk* stack, int op){ stack->array[++stack->top] = op;}

int evaluatePostfix(char * exp){
    struct stk* stack = createStack(strlen(exp));
    int i;
    for(i = 0; exp[i]; i++){
        if(isdigit(exp[i])) push(stack,exp[i] - '0');

        else{
            int val1 = pop(stack);
            int val2 = pop(stack);
            printf("\nValues are %d and %d",val1,val2);
            switch(exp[i]){
                case '/': push(stack, val2/val1); break;
                case '*': push(stack, val2*val1); break;
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2-val1); break;
            }
        }
    }
    return pop(stack);
}

int main(){
    char exp [] = "54+82/3*-";

    int res = evaluatePostfix(exp);
    printf("\nEvaluated value is: %d",res);
}

