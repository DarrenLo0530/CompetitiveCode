#include <bits/stdc++.h>
using namespace std;

struct Node {
    int prefixFreq, suffixFreq, maxFreq;
};

int data[100010];
Node tree[(1 << 18)];

Node merge(Node &left, Node &right, int l1, int r1, int l2, int r2){
    int maxFreq = max(left.maxFreq, right.maxFreq);
    int prefixFreq = left.prefixFreq;
    int suffixFreq = right.suffixFreq;

    if(data[r1] == data[l2]){
        maxFreq = max(maxFreq, left.suffixFreq + right.prefixFreq);
        //Left node has all same elements
        if(data[l1] == data[r1]){
            prefixFreq = left.suffixFreq + right.prefixFreq;
        }

        //Right node has all same elements
        if(data[l2] == data[r2]){
            suffixFreq = left.suffixFreq + right.prefixFreq;
        }
    }

    return Node {prefixFreq, suffixFreq, maxFreq};
}


void buildTree(int l, int r, int treeIndex){
    if(l == r){
        tree[treeIndex] = Node{1, 1, 1};
        return;
    }

    int mid = (l + r)/2;
    buildTree(l, mid, treeIndex * 2);
    buildTree(mid + 1, r, treeIndex * 2 + 1);
    
    tree[treeIndex] = merge(tree[treeIndex*2], tree[treeIndex*2 + 1], l, mid, mid+1, r);
}

Node query(int queryLeft, int queryRight, int l, int r, int treeIndex){
    if(queryLeft > r || queryRight < l){
        return Node{0, 0, 0};
    }

    if(l >= queryLeft && r <= queryRight){
        return tree[treeIndex];
    }

    int mid = (l + r)/2;

    Node left = query(queryLeft, queryRight, l, mid, treeIndex*2);
    Node right = query(queryLeft, queryRight, mid + 1, r, treeIndex*2 + 1);

    return merge(left, right, l, mid, mid+1, r);
}

int main(){
    while(true){
        memset(data, 0, sizeof(data));
        memset(tree, 0, sizeof(tree));
        
        int n, q;
        scanf("%d", &n);

        if(n == 0){
            break;
        }

        scanf("%d", &q);

        for(int i = 1; i<=n; i++){
            scanf("%d", &data[i]);
        }

        buildTree(1, n, 1);

        while(q--){
            int i, j;
            scanf("%d%d", &i, &j);
            cout << query(i, j, 1, n, 1).maxFreq <<'\n';
        }
    }    
}
