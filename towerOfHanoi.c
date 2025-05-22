#include<stdio.h>
int count = 0;
void TOH(int n, char S, char D, char Aux){
    if(n == 0) return;

    else{
        TOH(n-1,S,Aux,D);
        count++;
        printf("Move %d disk from %c to %c\n",n,S,D); 
        TOH(n-1,Aux,D,S);
    }
   
}

int main(){
    int n;
    printf("Enter the disk number: ");
    scanf("%d",&n);

    TOH(n,'S','D','A');
    printf("%d ",count);
}