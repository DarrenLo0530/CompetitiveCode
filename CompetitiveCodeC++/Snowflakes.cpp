#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int arms[12];

int calculateVal(int l){
    int ans = 0;
    for(int i = 1; i<=6; i++){
        ans += arms[l+i-1]*i;
    }

    return ans;
}
int main(){
    int N;
    scanf("%d", &N);
    set<vector<int>> used;

    for(int i = 0; i<N; i++){
        int min = INF;
        int ans[6];
        int a;

        for(int j = 0; j<6; j++){
            scanf("%d", &a);
            arms[j] = a;
            arms[j+6] = a;
        }

        for(int i = 0; i<6; i++){
            int n = calculateVal(i);     
            if(n < min){
                copy(arms + i, arms+6+i, ans);
                min = n;
            }       
        }

        reverse(arms, arms+12);

        for(int i = 0; i<6; i++){
            int n = calculateVal(i);     
            if(n < min){
                copy(arms + i, arms+6+i, ans);
                min = n;
            }       
        }

        vector<int> hsh;
        for(int i = 0; i<6; i++){
            hsh.push_back(ans[i]);
        }

        used.insert(hsh);
    } 
    
    if(used.size() != N){
        cout<<"Twin snowflakes found."<<"\n";
    } else {
        cout<<"No two snowflakes are alike."<<"\n";
    }

}
