#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int mx = 100001;

bool visited[mx];
vector<pii> adj[mx];
vector<int> largest;
vector<int> distances;

pii findFurthest(int curr, int par, bool mark){ //node, dist
    if(mark){
        //cout << "Marked " << curr << '\n';
        visited[curr] = mark;
    }
    pii furthest = {curr, 0};
    for(pii i: adj[curr]){
        if(i.first != par){
            pii next = findFurthest(i.first, curr, mark);
            if(next.second + i.second > furthest.second){
                furthest = next;
                furthest.second += i.second;
            }
        }
    }
    return furthest;
}

int mid;
int dfs(int start, int dest, int par, int total){
    if(start == dest){
        return 0;
    }
    for(pii i: adj[start]){
        if(i.first != par){
            int dist = dfs(i.first, dest, start, total);
            if(dist >= 0){
                mid = min(mid, max(total-dist, dist));
                return dist + i.second;
            }
        }
    }
    return -1;
}

int travelTime(int N, int M, int L){
    int ans = 0;
    for(int i = 0; i<N; i++){
        if(!visited[i]){
            //cout << i << '\n';
            int root = findFurthest(i, -1, false).first;
            //cout << "Root : " << root << '\n';
            distances.clear();
            pii nd = findFurthest(root, -1, true);
            mid = 2*INF;
            dfs(root, nd.first, -1, nd.second);
            if(mid == 2*INF){
                mid = 0;
            }
            ans = max(ans, nd.second);
            largest.push_back(mid);
        }
    }

    sort(largest.begin(), largest.end(), greater<int>());
    if(largest.size() >= 2){
        ans = max(ans, largest[0] + largest[1] + L);
    }
    if(largest.size() >= 3){
        ans = max(ans, largest[1] + largest[2] + 2*L);
    }
    
    return ans;
}
int main(){

    int N, M, L;
    scanf("%d%d%d", &N, &M, &L);
    for(int i = 0; i<M; i++){
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }

   cout << travelTime(N, M, L) << '\n';

}