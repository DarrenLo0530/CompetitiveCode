#include <bits/stdc++.h>
using namespace std;


int peg[50];
int moveCount = 0;
bool noAns = false;

//Move 'disk' disks from peg start, to peg end using peg aux as storage
int solve(int disk, int start, int end, int aux){
    if(disk == 0){
        return 0;
    }

    //If largest disk is at start, then state is between moving the largest disk to the destination peg and moving all the disks off the largest peg
    if(peg[disk] == start){
        return solve(disk-1, start, aux, end);
    //If largest disk is already at end, then add number of steps required to get peg to destination. Then state is between after moving disk to destination peg and end of game
    } else if(peg[disk] == end){
        return (1 << (disk-1)) + solve(disk-1, aux, end, start);
    }

    noAns = true;
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", peg + i);
    }

    int ans = solve(n, 1, 2, 3);
    if(noAns){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
}