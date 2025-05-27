#include<stdio.h>

void insertionSort(int arr[],int n){
    int i = 1;

    while(i < n){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
        i++;
    }
}

int main(){
    int arr[5] = {1,3,2,4,5};
    printf("Array before sorting : ");
    for(int i=0; i<5; i++)
    printf("%d ",arr[i]);

    printf("\nArray after the sorting: ");
    insertionSort(arr,5);

    for(int i=0; i<5; i++)
    printf("%d ",arr[i]);
    
}