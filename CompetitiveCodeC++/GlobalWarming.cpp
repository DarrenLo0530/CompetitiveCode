#include <bits/stdc++.h>
using namespace std;

int N;
int nums[21];
int pattern[21];


int getPat(){
    for(int i = 0; i<=N-2; i++){
        for(int j = 0; j<=i; j++){
            pattern[j] = nums[j+1] - nums[j];
        }

        for(int j = 0; j<=N-2; j++){
            if(nums[j+1] - nums[j] != pattern[j % (i+1)]){
                break;
            }

            if(j == N-2){
                return i+1;
            }
        }
    }

    return 0;
}

int main(){
    while(true){
        scanf("%d", &N);
        if(!N){
            break;
        }

        for(int i = 0; i<N; i++){
            scanf("%d", &nums[i]);
        }

        cout<<getPat()<<"\n";

    }
    
}