#include <bits/stdc++.h>
using namespace std;

int N;
int nums[20];

void printArr(){
    for(int i = 0; i<N; i++){
        printf("%d ", nums[i]);
    }
    cout<<"\n";
}
int bubbleSort(){
    int numSwaps = 0;

    for(int i = 0; i<N-1; i++){
        if(nums[i] > nums[i+1]){
            swap(nums[i], nums[i+1]);
            printArr();
            numSwaps++;
        }
    }

    return numSwaps;
}


int main(){
    cin>>N;
    for(int i = 0; i<N; i++){
        cin>>nums[i];
    }
    printArr();
    int numSwaps = 1;
    while(numSwaps){
        numSwaps = bubbleSort(); 
    }
}