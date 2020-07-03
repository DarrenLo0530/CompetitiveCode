#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll NEG_INF = -0x3f3f3f3f;

struct Node{
    ll prefixSum, suffixSum, totalSum, maxSum;
};

Node segtree[(1 << 18)];
int n;
int data[50010];

Node merge(Node left, Node right){
    ll totalSum = left.totalSum + right.totalSum;
    ll prefixSum = max(max(left.prefixSum, left.totalSum + right.prefixSum), totalSum);
    ll suffixSum = max(max(right.suffixSum, right.totalSum + left.suffixSum), totalSum);
    ll maxSum = max(max(max(max(prefixSum, suffixSum), left.suffixSum + right.prefixSum), left.maxSum), right.maxSum);
    return Node{prefixSum, suffixSum, totalSum, maxSum};
}

void constructTree(int l, int r, int treeIndex){
    if(l == r){
        segtree[treeIndex] = Node{data[l], data[l], data[l], data[l]};
        return;
    }
    int mid = (l+r)/2;
    constructTree(l, mid, treeIndex * 2);
    constructTree(mid + 1, r, treeIndex * 2 + 1);

    segtree[treeIndex] = merge(segtree[treeIndex*2], segtree[treeIndex*2 + 1]);
}

Node query(int queryLeft, int queryRight, int l, int r, int treeIndex){
    if(l > queryRight || r < queryLeft){
        return Node{NEG_INF, NEG_INF, NEG_INF, NEG_INF};
    } else if(l >= queryLeft && r <= queryRight){
        return segtree[treeIndex];
    }
    
    int mid = (l + r)/2;
    Node left = query(queryLeft, queryRight, l, mid, treeIndex * 2);
    Node right = query(queryLeft, queryRight, mid + 1, r, treeIndex * 2 + 1);
    return merge(left, right);
}

int main(){
    scanf("%d", &n);

    for(int i = 1; i<=n ;i++){
        scanf("%d", &data[i]);
    }

    int m;
    scanf("%d", &m);
    
    constructTree(1, n, 1);
    
    while(m--){
        int x, y;
        scanf("%d%d", &x, &y);
        cout << query(x, y, 1, n, 1).maxSum << endl;
    }
    
}