#include <bits/stdc++.h>
using namespace std;
#define NINF -0x3f3f3f3f
#define pb push_back

struct Node{
    int largest, secondLargest;
};

int data[100010];
Node tree[(1<<18)];

Node merge(Node& left, Node& right){
    vector<int> order;
    order.pb(left.largest);
    order.pb(left.secondLargest);
    order.pb(right.largest);
    order.pb(right.secondLargest);

    sort(order.begin(), order.end(), greater<int>());
    return Node{order[0], order[1]};
}

void update(int l, int r, int updateIndex, int newValue, int index){
    if(l == r && l == updateIndex){
        tree[index] = Node{newValue, NINF};
        return;
    }

    if(updateIndex <= r && updateIndex >= l){
        int mid = (l+r)/2;
        update(l, mid, updateIndex, newValue, index*2);
        update(mid+1, r, updateIndex, newValue, index*2+1);
        tree[index] = merge(tree[index*2], tree[index*2+1]);
    }
}

void buildTree(int n){
    for(int i = 1; i<=n; i++){
        update(1, n, i, data[i], 1);
    }
}

Node query(int queryLeft, int queryRight, int l, int r, int index){
    if(l > queryRight || r < queryLeft){
        return Node{NINF, NINF};
    }

    if(l >= queryLeft && r <= queryRight){
        return tree[index];
    }

    int mid = (l+r)/2;
    Node left = query(queryLeft, queryRight, l, mid, index*2);
    Node right = query(queryLeft, queryRight, mid+1, r, index*2 + 1);
    return merge(left, right);
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i<=n; i++){
        scanf("%d", data + i);
    }

    buildTree(n);

    int q;
    scanf("%d", &q);
    while(q--){
        char o;
        int x, y;
        scanf(" %c%d%d", &o, &x, &y);
        if(o == 'Q'){
            Node ans = query(x, y, 1, n, 1);
            cout << ans.secondLargest + ans.largest << '\n';
        } else {
            update(1, n, x, y, 1);
        }        
    }
}