#include <bits/stdc++.h>
using namespace std;
int N, m, x, y;
int fp[14];

int getHeight(int level, int l, int prevHeight){

    if(level == 0){
        return prevHeight;
    }

    int dist = fp[level - 1];

    if (x >= l + dist && x < l + 2*dist){
        return getHeight(level - 1, l + dist, prevHeight += dist);
    } else if (x >= l + dist*2 && x < l + 3*dist){
        return getHeight(level - 1, l + dist*2, prevHeight += dist*2);
    } else if (x >= l + dist*3 && x < l + 4*dist){
        return getHeight(level - 1, l + dist*3, prevHeight += dist);
    } else {
        return prevHeight;
    }
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i<=13; i++){
        fp[i] = pow(5, i);
    }

    for(int i = 0; i<N; i++){
        scanf("%d %d %d", &m, &x, &y);
        int height = getHeight(m, 0, -1);
        
        if(height >= y){
            cout<<"crystal"<<'\n';
        } else {
            cout<<"empty"<<'\n';
        }
    }
}