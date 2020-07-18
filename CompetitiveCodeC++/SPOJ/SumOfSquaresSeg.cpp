#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 0x3f3f3f3f

struct Node {
    ll sum, squareSum, lazy0, lazy1;
};

int data[100010];
Node tree[(1 << 18)];

void propogate(int l, int r, int index){
    if(tree[index].lazy0 != INF){
        tree[index].sum = (r-l+1) * tree[index].lazy0;
        tree[index].squareSum = pow(tree[index].lazy0, 2) * (r-l+1);
    } else if(tree[index].lazy1){
        tree[index].squareSum += 2*tree[index].lazy1*tree[index].sum + (r-l+1) * pow(tree[index].lazy1, 2);
        tree[index].sum += tree[index].lazy1;
    }

    if(l != r){
        for(int child = index*2; child <= index*2+1; child++){
            if(tree[index].lazy0 != INF){
                tree[child].lazy0 = tree[index].lazy0;
                tree[child].lazy1 = 0;
            } else if(tree[index].lazy1){
                tree[child].lazy1 += tree[index].lazy1;
                if(tree[child].lazy0 != INF){
                    tree[child].lazy1 += tree[child].lazy0;
                }
                tree[child].lazy0 = INF;
            }
        }
    }

    tree[index].lazy0 = INF;
    tree[index].lazy1 = 0;
}

Node merge(Node &left, Node &right){
    int sum = left.sum + right.sum;
    int squareSum = left.squareSum + right.squareSum;
    return Node{sum, squareSum, INF, 0};
}

void buildTree(int l, int r, int index){
    if(l == r){
        tree[index] = Node{data[l], data[l] * data[l], INF, 0};
        return;
    }

    int mid = (l + r)/2;
    buildTree(l, mid, index*2);
    buildTree(mid+1, r, index*2+1);
    tree[index] = merge(tree[index*2], tree[index*2+1]);
}

void rangeUpdate(int updateLeft, int updateRight, int l, int r, int type, int update, int index){
    propogate(l, r, index);

    if(updateRight < l || updateLeft > r){
        return;
    }

    if(l >= updateLeft && r <= updateRight){
        if(type == 0){
            tree[index].lazy0 = update;
        } else {
            tree[index].lazy1 = update;    
        }
        propogate(l, r, index);
        return;
    }

    int mid = (l+r)/2;
    rangeUpdate(updateLeft, updateRight, l, mid, type, update, index*2);
    rangeUpdate(updateLeft, updateRight, mid+1, r, type, update, index*2+1);
    tree[index] = merge(tree[index*2], tree[index*2+1]);
}

Node query(int queryLeft, int queryRight, int l, int r, int index){
    propogate(l, r, index);
    
    if(queryRight < l || queryLeft > r){
        return Node{0, 0, 0, 0};
    }

    if(l >= queryLeft && r <= queryRight){
        return tree[index];
    }
    
    int mid = (l+r)/2;
    Node left = query(queryLeft, queryRight, l, mid, index*2);
    Node right = query(queryLeft, queryRight, mid+1, r, index*2+1);
    return merge(left, right);
}

int main(){
    int t;
    scanf("%d", &t);

    for(int c = 1; c<=t; c++){
        memset(data, 0, sizeof(data));
        for(int i = 0; i < (1<<18); i++){
            tree[i] = Node{0, 0, 0, 0};
        }

        printf("Case %d:\n", c);

        int n, q;
        scanf("%d%d", &n, &q);

        for(int i = 1; i<=n; i++){
            scanf("%d", data + i);  
        }

        buildTree(1, n, 1);
        while(q--){
            int o, st, nd;
            scanf("%d%d%d", &o, &st, &nd);
            
            if(o == 2){
                Node res = query(st, nd, 1, n, 1);
                cout<<res.squareSum<<'\n';
            } else {
                int x;
                scanf("%d", &x);
                rangeUpdate(st, nd, 1, n, o, x, 1);
            }
        }
    }
}