#include <bits/stdc++.h>
using namespace std;

int st[1<<20];
int lt[1<<20];
int q[1<<20];
int qlt[1<<20];

int summation(int l, int r){
    return (l+r)/2 * (r-l+1);
}

void rangeIncrement(int l, int r, int val1, int val2, int currNode, int nl, int nr){
    if(nl > nr || nr < l || nl > r){
        return;
    }

    if(qlt[currNode] != 0 || lt[currNode] != 0){
        st[currNode] += (nr-nl+1) * lt[currNode];
        q[currNode] += summation(nl, nr) * qlt[currNode];
          
        if(nr != nl){
            lt[currNode*2] += lt[currNode], lt[currNode*2+1] += lt[currNode];
            qlt[currNode*2] += qlt[currNode], qlt[currNode*2+1] += qlt[currNode];
        }
        lt[currNode] = qlt[currNode] = 0; 
    }

    if(nl >= l && nr <= r){ //Nodes range is all part of query range
        st[currNode] += (nr-nl+1) * val1;
        q[currNode] += summation(nl, nr) * val2;

        if(nl != nr){
            lt[currNode*2] += val1, lt[currNode*2+1] += val1;
            qlt[currNode*2] += val2, qlt[currNode*2+1] += val2;
        }
        return;
    }

    int mid = (nl + nr)/2;
    rangeIncrement(l, r, val1, val2, currNode*2, nl, mid);
    rangeIncrement(l, r, val1, val2, currNode*2+1, mid+1, nr);

    st[currNode] = st[currNode*2+1] + st[currNode*2];
    q[currNode] = q[currNode*2+1] + q[currNode*2];
}

int query(int l, int r, int currNode, int nl, int nr){
    if(nl > nr || nr < l || nl > r){
        return 0;
    }

    if(qlt != 0 || lt[currNode] != 0){
        st[currNode] += (nr-nl+1) * lt[currNode];
        q[currNode] += summation(nl, nr) * qlt[currNode];
          
        if(nr != nl){
            lt[currNode*2] += lt[currNode], lt[currNode*2+1] += lt[currNode];
            qlt[currNode*2] += qlt[currNode], qlt[currNode*2+1] += qlt[currNode];
        }
        lt[currNode] = qlt[currNode] =  0; 
    }

    if(nl >= l && nr <= r){
        return st[currNode] + q[currNode];
    }

    if(r > nl || l < nr){ //Part of nodes range is
        int mid = (nl + nr)/2;
        return query(l, r, currNode*2, nl, mid) + query(l, r, currNode*2+1, mid+1, nr);
    }

    return 0;
}

int main(){
    
    int N, Q, o, l, r, a;
    scanf("%d %d", &N, &Q);

    for(int i = 0; i<Q; i++){
        scanf("%d", &o);
        if(o == 1){
            scanf("%d %d %d", &l, &r, &a);
            rangeIncrement(l, r, a*(1-l), a, 1, 0, (1<<19)-1);
        } else {
            scanf("%d %d", &l, &r);
            cout<<query(l, r, 1, 0, (1<<19)-1)<<"\n";
        }
    }
}