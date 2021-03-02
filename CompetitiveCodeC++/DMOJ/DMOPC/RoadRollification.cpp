#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 2e5 +1;
int a[MX];
ll numPeopleOut[MX];
ll numPeopleIn[MX];
vector<int> og[MX];
vector<int> rev[MX];


/*
For each node count the number of people that can reach current node and number of people that it can reach
Assume we have an edge from a->b
then when node goes a <- b, all the people that can reach b will be able to reach all the people that a can reach. We need to
take into account that the number of people that can reach b takes into account the number of people that can reach a. This
will double count. So subtract the number of people that can reach "a" from the number of people that can reach "b". Likewise,
same thing holds true for number of people that a can reach. Likewise subtract number of people that "b" reaches from "a". Then
multiply to find number of new connections. You can find total connections by counting number of people that each node reaches -1
and multiplying by number of people at current node. (subtract 1 since you dont want to count connection between a person and themselvees)
*/

ll dfs(int curr, ll arr[], vector<int> adj[]){
    if(arr[curr] != 0){
        return arr[curr];
    }
    arr[curr] = a[curr];
    for(int i: adj[curr]){
        arr[curr] += dfs(i, arr, adj);
    }

    return arr[curr];
}

int main(){ 
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        scanf("%d", a+i);
    }

    for(int i = 0; i<n-1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        og[u].push_back(v);
        rev[v].push_back(u);
    }

    for(int i = 0; i<=n; i++){
        dfs(i, numPeopleOut, og);
        dfs(i, numPeopleIn, rev);
    }

    ll ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j: og[i]){
            ans = max(ans, (numPeopleIn[j] - numPeopleIn[i]) * (numPeopleOut[i] - numPeopleOut[j]));
        }
    }
    
    for(int i = 1; i<=n; i++){
        ans += a[i] * (numPeopleOut[i]-1);
    }


    printf("%lld\n", ans);
}