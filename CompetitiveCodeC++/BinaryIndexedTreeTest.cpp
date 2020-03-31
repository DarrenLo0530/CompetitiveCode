#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 100001;

int N, M;
ll arrBit[mx];
ll arrDat[mx];

ll freqBit[mx];
ll freqDat[mx];

void add(int idx, int num, ll (&bit)[mx]){
    while(idx <= mx){
        bit[idx] += num;
        idx = idx + (idx&(-idx));
    }
}

void change(int idx, int num){
    int og = arrDat[idx];
    int diff = num - arrDat[idx];
    freqDat[og]--;
    freqDat[num]++;
    arrDat[idx] = num;

    add(og, -1, freqBit);
    add(num, 1, freqBit);
    add(idx, diff, arrBit);
}

ll sum(int idx, ll (&bit)[mx]){
    ll res = 0;
    while(idx != 0){
        res+=bit[idx];
        idx = idx - (idx&(-idx));
    }

    return res;
}

ll query(int num){
    return sum(num, freqBit);
}




int main(){

    char operation;
    int a, b;
    scanf("%d %d", &N, &M);

    for(int i = 1; i<=N; i++){
        scanf("%d", &arrDat[i]);
        add(i, arrDat[i], arrBit);
        freqDat[arrDat[i]]++;
    }

    for(int i = 1; i<=100000; i++){
        add(i, freqDat[i], freqBit);
    }

    for(int i =0; i<M; i++){
        scanf(" %c", &operation);
        if(operation == 'C'){
            scanf("%d %d", &a, &b);
            change(a, b);
        } else if (operation == 'S'){
            scanf("%d %d", &a, &b); 
            cout<<(sum(b, arrBit) - sum(a-1, arrBit))<<"\n";
        } else {
            scanf("%d", &a);
            cout<<query(a)<<"\n";
        }
    }
}