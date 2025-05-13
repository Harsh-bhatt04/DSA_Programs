#include<stdio.h>
#include<string.h>
#define MAX 100
char stk[MAX];
int TOP = -1;
int precedenceCheck(char op){
    switch(op){
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return -1;
    }
}
char associativity(char ch){
    if(ch == '^') return 'R';
    else return 'L';
}
void infixToPostfix(char str[],int n){
    char res[100];
    int ri = 0,si = -1;
    for(int i=0; i<n; i++){
        char ch = str[i];
        if((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9' ))
            res[ri++] = ch;
        else if(ch == '(')
            stk[++TOP] = ch;
        else if(ch == ')'){
            while(TOP != -1 && stk[TOP] != '('){
                char c = stk[TOP];
                TOP--;
                res[ri++] = c;
            }
            TOP--;
        }
        else{
            while(TOP != -1 && (precedenceCheck(str[i]) < precedenceCheck(stk[TOP]) || precedenceCheck(str[i]) == precedenceCheck(stk[TOP]) && associativity(str[i]) == 'L')){
                res[ri++] = stk[TOP--];
            }
            stk[++TOP] = ch;
        }
        }
        // Pop remaining operators from the stack
        while (TOP != -1) {
            res[ri++] = stk[TOP--];
        }
    
        // Null-terminate the result string
        res[ri] = '\0';
        printf("%s\n", res);
}

int main(){
    char infix[20];
    printf("Enter the Infix expression: ");
    gets(infix);

    int n = strlen(infix);

    printf("Postfix expression is: ");
    infixToPostfix(infix,n);
    
}