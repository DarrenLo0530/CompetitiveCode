#include <bits/stdc++.h>
using namespace std;

bool lose[100001];

int main(){
    int N, K, a;
    cin>>N>>K;

    vector<int> stones;

    for(int i = 0; i<N; i++){
        cin>>a;
        stones.push_back(a);
    }

    for(int i = 0; i<=K; i++){
        lose[i] = true;
        for(int j: stones){
            if(i - j < 0){
                break;
            }

            if(lose[i-j]){
               lose[i] = false; 
               break;
            }
        }
    }

    if(lose[K]){
        cout<<"Second"<<"\n";
    } else {
        cout<<"First"<<'\n';
    }

}