#include<stdio.h>
int Hoare_Partition(int arr[], int p, int r){
    int x = arr[p];
    int i = p - 1;
    int j = r + 1;

    while(1){
        do{
            j = j - 1;
        }while(arr[j] > x);

        do{
            i = i + 1;
        }while(arr[i] < x);

        if(i < j){
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else 
            return j;
    }
}

void QuickSort(int arr[], int p, int r){
    if( p < r){
        int q = Hoare_Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }

}

int main(){
    int arr[5] = {1,2,3,4,5};
    printf("Array before Sorting :");
    for(int i=0; i<5; i++){
        printf("%d ",arr[i]);
    }

    QuickSort(arr,0,4);
    printf("\nArray after Sorting :");
    for(int i=0; i<5; i++){
        printf("%d ",arr[i]);
    }
}
