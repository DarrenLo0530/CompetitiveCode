#include <bits/stdc++.h>
using namespace std;

int data[50001];
int upper(int l, int r, int h){
    if(l > r){
        return l;
    }
    
    int mid = (l+r)/2;
    if(h >= data[mid]){
        return upper(mid+1, r, h);
    } else {
        return upper(l, mid-1, h);
    }
}    

int lower(int l, int r, int h){
    if(l > r){
        return r;
    }

    int mid = (l+r)/2;
    if(h > data[mid]){
        return lower(mid+1, r, h);
    } else {
        return lower(l, mid-1, h);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", data + i);
    }

    int q;
    scanf("%d", &q);
    for(int i = 0; i<q; i++){
        int h;
        scanf("%d", &h);
        int taller = upper(1, n, h);
        int smaller = lower(1, n, h);

        if(smaller < 1){
            cout << 'X';
        } else {
            cout << data[smaller];
        }

        if(taller > n){
            cout << " X";
        } else {
            cout << " " << data[taller];
        }

        cout << '\n';
    }
}