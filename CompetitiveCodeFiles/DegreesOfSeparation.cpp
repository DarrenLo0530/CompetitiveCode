#include <bits/stdc++.h>
using namespace std;
set<int> adj[52];

void ie(int x, int y){
    adj[x].insert(y);
    adj[y].insert(x);
}

void rem(int x, int y){
    adj[x].erase(y);
    adj[y].erase(x);

}

int numFriends(int x){
    return adj[x].size();
}

int friendsOfFriends(int x){
    set<int> fof;
    for(int i: adj[x]){
        for(int k: adj[i]){
            if(adj[x].find(k) == adj[x].end() && k != x){
                fof.insert(k);
            }
        }
    }

    return fof.size();
}

int degreesOfSeparation(int x, int y){
    bool visited[52] = {false};

    queue<int> tv;
    tv.push(x);
    visited[x] = true;

    for(int i = 0; i<52; i++){
        queue<int> nextTv;
        while(!tv.empty()){
            int next = tv.front();
            tv.pop();

            if(next == y){
                return i;
            }

            for(int j: adj[next]){
                if(!visited[j]){
                    visited[j] = true;
                    nextTv.push(j);
                }
            }
        }
        tv = nextTv;
    }
    return -1;
}

int main(){
    char o;
    int a, b;

    ie(1, 6);
    ie(2, 6);
    ie(3, 6);
    ie(4, 6);
    ie(5, 6); 
    ie(3, 5);
    ie(3, 4);
    ie(4, 5);
    ie(6, 7);
    ie(7, 8);
    ie(8, 9);
    ie(9, 12);
    ie(9, 10);
    ie(10, 11);
    ie(11, 12);
    ie(3, 15);
    ie(12, 13);
    ie(13, 15);
    ie(13, 14);
    ie(16, 18);
    ie(16, 17);
    ie(17, 18);

    while(true){
        scanf(" %c", &o);
        if(o == 'i'){
            scanf("%d %d", &a, &b);
            ie(a, b);
        } else if (o == 'd'){
            scanf("%d %d", &a, &b);
            rem(a, b);
        } else if (o == 'n'){
            scanf("%d", &a);
            cout<<numFriends(a)<<"\n";
        } else if (o == 'f'){
            scanf("%d", &a);
            cout<<friendsOfFriends(a)<<"\n";
        } else if (o == 's'){
            scanf("%d %d", &a, &b);  
            int deg = degreesOfSeparation(a, b);
            if(deg == -1){
                cout<<"Not connected"<<"\n";
            } else {
                cout<<deg<<"\n";
            }
        } else {
            break;
        }
    }
}