#include <bits/stdc++.h>
using namespace std;

struct Node{
    int unusedOpening, unusedClosing;
};

void updateNode(Node segtree[], int index){
    Node leftNode = segtree[index*2+1];
    Node rightNode = segtree[index*2+2];

    int bracketsFormed = min(leftNode.unusedOpening, rightNode.unusedClosing);

    int unusedOpening = leftNode.unusedOpening - bracketsFormed + rightNode.unusedOpening;
    int unusedClosing = rightNode.unusedClosing - bracketsFormed + leftNode.unusedClosing;
    segtree[index] = Node{unusedOpening, unusedClosing};
    
}

void solve (){
    int n;
    scanf("%d", &n);

    Node segtree[(1 << 16)];

    fill(segtree + ((1 << 15) - 1), segtree + (1 << 16), Node{0, 0});

    for(int i = 0; i<n; i++){
        char c;
        scanf(" %c", &c);

        Node leaf;
        if(c == '('){
            leaf = Node{1, 0};
        } else {
            leaf = Node{0, 1};
        }
        segtree[(1 << 15) - 1 + i] = leaf;
    }

    for(int i = (1<<15) - 2; i>=0; i--){
        updateNode(segtree, i);
    }

    //cout << segtree[0].unusedOpening << '\n';
    //cout << segtree[0].unusedClosing <<'\n';   

    int k;
    scanf("%d", &k);

    while(k--){
        int opp;
        scanf("%d", &opp);

        if(opp){
            int index = (1 << 15) - 1 + opp-1;
            swap(segtree[index].unusedClosing, segtree[index].unusedOpening);

            while(index != 0){
                index = (index - 1)/2;
                updateNode(segtree, index);
            }
        } else {
            if(segtree[0].unusedOpening == 0 && segtree[0].unusedClosing == 0){
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    
}

int main(){
    for(int a = 1; a<=10; a++){
        printf("Test %d:\n", a);
        solve();
        
    }
}