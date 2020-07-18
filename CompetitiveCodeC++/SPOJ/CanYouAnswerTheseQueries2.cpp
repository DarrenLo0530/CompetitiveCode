#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    ll currMaxSum, globMaxSum, lazy, bestLazy;
};

int vis[200010];
Node tree[400001];
int data[100001];
int ans[100001];
vector<pair<pair<int, int>, int>> queries;

bool sortSec(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
    return (a.first.second < b.first.second);
}

void propogate(int l, int r, int index){
    //At some node, propogate all the range updates it stores to it's children (Itself was already updated by previous propogation)
    if(l == r){
        return;
    }

    for(int i = index*2; i<=index*2+1; i++){
        //Lets say you have list [1, 2, 5, 3, -2, -6(i) ...]
        //You've range updated up to -6 or index i
        //for range(1 to 2), lazy would be [5, 3, -2, -6] assuming we do not propogate
        //bestLazy is the largest prefix of the lazy which is [5, 3] which when propogating is used to get our glob maxsum
        //currMaxSum is just the maximum summation of the numbers up to the current index i starting from every number in range [l..r]
        tree[i].bestLazy = max(tree[i].bestLazy, tree[i].lazy + tree[index].bestLazy);
        tree[i].lazy += tree[index].lazy;
        tree[i].globMaxSum = max(tree[i].globMaxSum, tree[index].bestLazy + tree[i].currMaxSum);
        tree[i].currMaxSum += tree[index].lazy;
    }

    tree[index].bestLazy = tree[index].lazy = 0;
}

void rangeUpdate(int lUpdate, int rUpdate, int l, int r, int index, int amount){
    if(tree[index].lazy != 0){
        propogate(l, r, index);
    }

    if(lUpdate > r || rUpdate < l){
        return;
    } 

    if(l >= lUpdate && r <= rUpdate){
        tree[index].lazy = amount;
        tree[index].bestLazy = amount;
        tree[index].currMaxSum += amount;
        tree[index].globMaxSum = max(tree[index].globMaxSum, tree[index].currMaxSum);
        propogate(l, r, index);
        return;
    }

    int mid = (l + r)/2;
    rangeUpdate(lUpdate, rUpdate, l, mid, index*2, amount);
    rangeUpdate(lUpdate, rUpdate, mid + 1, r, index*2 + 1, amount);
    //You can not be sure that the previous currmaxsum was updated by this range update
    tree[index].currMaxSum = max(tree[index*2].currMaxSum, tree[index*2+1].currMaxSum);
    tree[index].globMaxSum = max(tree[index].currMaxSum, tree[index].globMaxSum);
}

int query(int lQuery, int rQuery, int l, int r, int index){
    if(tree[index].lazy != 0){
        propogate(l, r, index);
    }

    if(lQuery > r || rQuery < l){
        return -0x3f3f3f3f;
    } 
    if(l >= lQuery && r <= rQuery){
        return tree[index].globMaxSum;
    }

    int mid = (l + r)/2;
    return max(query(lQuery, rQuery, l, mid, index*2), query(lQuery, rQuery, mid+1, r, index*2 + 1));
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", data + i);
    }

    int q;
    scanf("%d", &q);
    for(int i = 0; i<q; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        queries.push_back(make_pair(make_pair(x, y), i));
    }

    sort(queries.begin(), queries.end(), sortSec);
    int queryCounter = 0;

    for(int i = 1; i<=n; i++){
        int lSlice = vis[data[i] + 100000] + 1;
        rangeUpdate(lSlice, i, 1, n, 1, data[i]);

        while(true){
            if(queries[queryCounter].first.second != i){
                break;
            }

            int x = queries[queryCounter].first.first;
            ans[queries[queryCounter].second] = query(x, i, 1, n, 1);
            queryCounter++;
        }

        vis[data[i] + 100000] = i;
    }

    for(int i = 0; i<q; i++){
        cout << ans[i] << '\n';
    }
}