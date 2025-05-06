// #include<iostream>
// #include<vector>
// #include <climits>

// using namespace std;

// int main(){
//     int n;
//     printf("Enter the size: ");
//     scanf("%d",&n);

//     int arr[n];
//     for(int i=0; i<n; i++){
//         scanf("%d",&arr[i]);
//     }
//     vector<int>temp;
//     int mini = INT_MAX;

//     if(arr[0] < arr[1]){
//         mini = arr[0];
//         temp.push_back(arr[1]);
//     }
//     else{
//         mini = arr[1];
//         temp.push_back(arr[0]);
//     }
    
//     // for(int i=1; i<n; i++){
//     //     if(arr[i] < mini){
//     //         mini = arr[i];
//     //         temp.push_back(arr[i]);
//     //     }
//     // }
//     for(int i=2; i<n; i+=2){
//         int tmin;
//         if(arr[i] < arr[i+1]){
//             tmin = arr[i];
//             // tmin2 = arr[i+1];
//         }
//         else{
//             tmin = arr[i+1];
//             // tmin2 = arr[i];
//         }
//         if(tmin < mini ){
//             temp.clear();
//             temp.push_back(mini);
//             mini = tmin;
//         }
//         else{
//             temp.push_back(tmin);
//         }
//     }
    

//     for(int i=0; i<temp.size(); i++){
//         cout<<temp[i]<<" ";
//     }

//     int secMin = INT_MAX;
//     for(int i=0; i<temp.size(); i++){
//         if(temp[i] < secMin)
//             secMin = temp[i];
//     }

//     cout<<" Sec minimum is: "<<secMin;

// }


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int n;
    printf("Enter the size (even only): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Only even-sized arrays are supported.\n");
        return 0;
    }

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Track defeated elements for each index
    vector<vector<int>> defeated(n);
    vector<int> currentIndices;

    // Push all initial indices
    for(int i = 0; i < n; i++) currentIndices.push_back(i);

    // Tournament rounds
    while(currentIndices.size() > 1) {
        vector<int> nextRound;
        for(int i = 0; i < currentIndices.size(); i += 2) {
            int a = currentIndices[i];
            int b = currentIndices[i+1];
            int winner, loser;

            if(arr[a] < arr[b]) {
                winner = a;
                loser = b;
            } else {
                winner = b;
                loser = a;
            }

            // Track the loser
            defeated[winner].push_back(arr[loser]);

            // Inherit loser's defeated values
            // for(int val : defeated[loser]) {
            //     defeated[winner].push_back(val);
            // }

            nextRound.push_back(winner);
        }
        currentIndices = nextRound;
    }

    int miniIndex = currentIndices[0];
    int mini = arr[miniIndex];

    // Find second minimum among elements defeated by the minimum
    int secMin = INT_MAX;
    for(int val : defeated[miniIndex]) {
        if(val < secMin) secMin = val;
    }

    cout << "Minimum: " << mini << endl;
    cout << "Second Minimum: " << secMin << endl;

    return 0;
}
