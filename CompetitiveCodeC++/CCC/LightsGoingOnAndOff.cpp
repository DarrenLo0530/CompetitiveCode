#include <bits/stdc++.h>
using namespace std;

int R, L, a;
set<int> ans;

void switchLights(int startIdx, vector<int> res){
    for(int i = startIdx; i < R; i++){
        res[i] = res[i-1] ^ res[i];
    }

    ans.insert(res[R-1]);
}


int main(){
    vector<int> lights(32);
    scanf("%d %d", &R, &L);

    for(int i = 0; i<R; i++){
        int hsh = 0;
        for(int j = 0; j<L; j++){
            scanf("%d", &a);
            hsh += a*(1<<j);
        }
        lights[i] = hsh;
    }   

    ans.insert(lights[R-1]);
    for(int i = 1; i<R; i++){
        switchLights(i, lights);
    }

    cout<<ans.size();
}