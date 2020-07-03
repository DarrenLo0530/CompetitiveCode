#include <bits/stdc++.h>
using namespace std;
vector<int> segtree[(1<<18)];
int original_data[100002];
pair<int, int> data[100002];

//Order range statistics

void buildTree(int l, int r, int currIndex) {
    //l is left side of range that currindex encompasses
    //r is right side of range that currindex encompasses
    //currIndex is idx in segtree array
    if (l == r){
        vector<int> x;
        x.push_back(data[l].second);
        segtree[currIndex] = x;
        return;
    }

    int mid = (l+r)/2;
    buildTree(l, mid, currIndex * 2);
    buildTree(mid + 1, r, currIndex*2 + 1);

    merge(segtree[currIndex*2].begin(), segtree[currIndex*2].end(), segtree[currIndex*2+1].begin(), segtree[currIndex*2+1].end(), back_inserter(segtree[currIndex]));
}

int query(int l, int r, int queryLeft, int queryRight, int q, int currIndex){
    if(l == r){
        return original_data[segtree[currIndex][0]];
    }
    //All elements encompassed by left child range are smaller than all elements in right child range since all leaf nodes are sorted by their values
    int endIndexesSmallerThanRange = lower_bound(segtree[currIndex*2].begin(), segtree[currIndex*2].end(), queryLeft) - segtree[currIndex*2].begin();
    int startIndexesGreaterThanRange = upper_bound(segtree[currIndex*2].begin(), segtree[currIndex*2].end(), queryRight) - segtree[currIndex*2].begin();
    int numberInRange = startIndexesGreaterThanRange - endIndexesSmallerThanRange;

    int mid = (l + r)/2;

    if(numberInRange >= q){
        return query(l, mid, queryLeft, queryRight, q, currIndex * 2);
    } else {
        q -= numberInRange;
        return query(mid + 1, r, queryLeft, queryRight, q, currIndex * 2 + 1);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i<=n; i++){
        scanf("%d", &original_data[i]);
        data[i] = make_pair(original_data[i], i);
    }

    sort(data+1, data+1+n);
    buildTree(1, n, 1);

    while(m--){
        int l, r, q;
        scanf("%d%d%d", &l, &r, &q);
        cout << query(1, n, l, r, q, 1) << '\n';
    }
}