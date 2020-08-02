#include <bits/stdc++.h>
using namespace std;

int heights[20000];


int main(){
    int l = 0, h = 0, r = 0;
    int maxr = 0;
    while(cin >> l >> h >> r){
        for(int i = l; i<r; i++){
            heights[i] = max(heights[i], h);
        }
        maxr = max(maxr, r);  
    }
    
    vector<int> ans;
    for(int i = 0; i<=maxr; i++){
        int prevHeight = i-1 >= 0 ? heights[i-1] : 0;

        if(heights[i] != prevHeight){
            cout<<i<<" "<<heights[i];
            
            if(i != maxr){
                cout<<" ";
            }
        }
    }

    cout<<'\n';
}