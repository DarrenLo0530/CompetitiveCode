#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

vector<int> graph[100001];

pair<int, int> dp(int curr, int par){
    //first = white, second = black;
    ll white = 1;
    ll black = 1;

    if(graph[curr].size() == 0){
        return make_pair(1, 1);
    }

    for(int i: graph[curr]){
        if(i == par){
            continue;
        }
        pair<int, int> res = dp(i, curr);
        white = (white * (res.first + res.second)) % mod;
        black = (black * res.first) % mod;
    }

    return make_pair(white, black);
}



int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n-1; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    pair<int, int> ans = dp(1, 0);
    cout<<(ans.second + ans.first) % mod;
}