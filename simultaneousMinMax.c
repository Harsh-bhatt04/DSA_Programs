#include<stdio.h>

int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    int mini = 0;
    int maxi = 0;
    int i = 0;
    if(n%2 != 0){
        mini = arr[0];
        maxi = arr[0];
        i = 1;
    }
    else{
        if(arr[0] < arr[1]){
            mini = arr[0];
            maxi = arr[1];
        }
        else{
            mini = arr[1];
            maxi = arr[0];
        }
        i = 2;
    }

    // while(i < n-1){
    //     int tmin,tmax;
    //     if(arr[i] < arr[i+1]){
    //         tmin = arr[i];
    //         tmax = arr[i+1];
    //     }
    //     else{
    //         tmin = arr[i+1];
    //         tmax = arr[i];
    //     }
    //     if(tmin < mini)
    //         mini = tmin;
    //     if(tmax > maxi)
    //         maxi = tmax;
    //     i += 2;   
    // }

    for( ; i < n-1 ; i += 2){
        int tmin,tmax;
        if(arr[i] < arr[i+1]){
            tmin = arr[i];
            tmax = arr[i+1];
        }
        else{
            tmin = arr[i+1];
            tmax = arr[i];
        }
        if(tmin < mini)
            mini = tmin;
        if(tmax > maxi)
            maxi = tmax;
    }
    printf("Maximum and Minimum are %d and %d ",maxi,mini);

}