#include <bits/stdc++.h>
using namespace std;

int N, M;
int v[100001];
pair<int, int> e[1000001];
bool u[1000001];

int getPar(int curr){
    if(v[curr] < 0){
        return curr;
    }
    int parent = getPar(v[curr]);
    v[curr] = parent;
    return parent;
}

int main(){
    scanf("%d %d", &N, &M);

    for(int i = 0; i<100001; i++){
        v[i] = -1;
    }

    for(int i = 0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        e[i] = make_pair(a, b);
    }

    for(int i = 0; i<M; i++){
        int par1 = getPar(e[i].first);
        int par2 = getPar(e[i].second);
        if(par1 != par2){
            u[i] = true;
            if(v[par1] < v[par2]){
                v[par1] += v[par2];
                v[par2] = par1;
            } else {
                v[par2] += v[par1];
                v[par1] = par2;
            }
        }
    }


    int prev = -1;
    for(int i = 1; i<N+1; i++){
        if(prev != -1 && prev != getPar(i)){
            cout<<"Disconnected Graph";
            prev = -1;
            break;
        } else {
            prev = getPar(i);
        }
    }

    if(prev>=0){
        for(int i = 0; i<M; i++){
            if(u[i]){
                cout<<i+1<<"\n";
            }
        }
    }
}