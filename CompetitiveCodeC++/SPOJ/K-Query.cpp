#include <bits/stdc++.h>
using namespace std;

//Offline querying
int ans[200010];
int tree[(1<<16)];

struct Query{
    int i, j, k;
};

struct QueryComparator{
    bool operator ()(const pair<Query, int> &q1, const pair<Query, int> &q2){
        return q1.first.k > q2.first.k;
    }
};

vector<pair<int, int>> data;
vector<pair<Query, int>> queries;

void insert(int l, int r, int location, int index){
    if(l == r && l == location){
        tree[index] = 1; 
        return;
    }

    if(location >= l && location <= r){
        int mid = (l+r)/2;
        insert(l, mid, location, index*2);
        insert(mid+1, r, location, index*2+1);
        tree[index] = tree[index*2] + tree[index*2+1];
    }

}

int query(int queryLeft, int queryRight, int l, int r, int index){
    if(r < queryLeft || l > queryRight){
        return 0;
    }

    if(l >= queryLeft && r <= queryRight){
        return tree[index];
    }

    int mid = (l+r)/2;
    return query(queryLeft, queryRight, l, mid, index*2) + query(queryLeft, queryRight, mid+1, r, index*2+1);
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        data.push_back(make_pair(x, i));
    }

    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());

    int q;
    scanf("%d", &q);

    for(int idx = 0; idx<q; idx++){
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        queries.push_back(make_pair(Query{i, j, k}, idx));
    }

    sort(queries.begin(), queries.end(), QueryComparator());

    int nextQuery = 0;
    int nextNum = 0;

    while(nextQuery < q && nextNum < n){
        while(data[nextNum].first > queries[nextQuery].first.k && nextNum < n){
            insert(1, n, data[nextNum].second, 1);
            nextNum++;
        }

        ans[queries[nextQuery].second] = query(queries[nextQuery].first.i, queries[nextQuery].first.j, 1, n, 1);
        nextQuery++;
    }

    //Already inserted all numbers so answer any remaining queries
    while(nextQuery < q){
        ans[queries[nextQuery].second] = query(queries[nextQuery].first.i, queries[nextQuery].first.j, 1, n, 1);
        nextQuery++;
    }

    for(int i = 0; i<q; i++){
        printf("%d\n", ans[i]);
    }   
}