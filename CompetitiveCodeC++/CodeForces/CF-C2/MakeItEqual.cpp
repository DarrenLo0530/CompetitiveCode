#include <bits/stdc++.h>
using namespace std;
int heightCount[200001];
int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    //Desired height is min height of all towers;
    int minH = 0x3f3f3f3f;
    for(int i = 0; i<n; i++){
        int h;
        scanf("%d", &h);
        heightCount[0]++;
        heightCount[h+1]--;
        minH = min(minH, h);
    }   

    for(int i = 1; i<=200001; i++){
        heightCount[i] += heightCount[i-1];
    }

    int ans = 0;
    int numSliced = 0;
    for(int h = 200000; h>minH; h--){
        //Cutting this layer will make the cut a bad cut, so we only take up until the previous layer.
        //Then we will assume that the next cut starts at this layer.
        if(numSliced + heightCount[h] > k){
            numSliced = heightCount[h];
            ans++;
        //We can include this layer in the cut, so increase amount of blocks the current cut is cutting out.
        } else {
            numSliced += heightCount[h];
        }
    }

    if(numSliced > 0){
        ans++;
    }

    cout<<ans<<'\n';
}