#include<stdio.h>

int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    
    int mini;
    if(arr[0] < arr[1]){
        mini = arr[0];
    }
    else{
        mini = arr[1];
    }
    for(int i=1; i<n; i++){
        if(arr[i] > mini){
            mini = arr[i];
            temp[i] = arr[i]; 
        }
    }

    for(int i=0; i<n; i++){
        printf("%d  ", temp[i]);
    }
    
}