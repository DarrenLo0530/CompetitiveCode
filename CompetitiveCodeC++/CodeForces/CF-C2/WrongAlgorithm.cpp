#include <bits/stdc++.h>
using namespace std;
void genWrong(int n){
    if(n < 6){
        cout<<-1<<'\n';
        return;
    } else {
        printf("%d %d\n", 1, 2);
        printf("%d %d\n", 1, 3);
        printf("%d %d\n", 1, 4);
        for(int i = 5; i<=n; i++){
            printf("%d %d\n", 2, i);
        }
    }
}

void genCor(int n){
    for(int i = 2; i<=n; i++){
        printf("%d %d\n", 1, i);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    genWrong(n);
    genCor(n);
}