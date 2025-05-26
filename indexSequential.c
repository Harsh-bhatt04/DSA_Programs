#include<stdio.h>

int indexSequentialSearch(int arr[],int n,int k,int group){
    int i = 0;
    while(arr[i] < k){
        i += group;
    }
    if(arr[i] == k) 
        return i;
    else{
        int low = i - group + 1;
        int high = i;

        while(low < high){
            if(arr[low] == k)
                return low;
            low++;
        }
    }

    return -1;
}
int main(){
    int n,k,group;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to be search : ");
    scanf("%d",&k);

    printf("Enter the grouping range: ");
    scanf("%d",&group);

    int result = indexSequentialSearch(arr,n,k,group);
    if(result == -1) 
    printf("Element not found");
    else 
    printf("Element found at %d index", result);
    
    
}