#include <bits/stdc++.h>
using namespace std;
int INF = 0x3f3f3f3f;

int main(){
    int N, l, r;
    int xR = 1, xL = 1;
    int xRAns = 0, xLAns = 0;
    int newXRAns, newXLAns;

    scanf("%d", &N);
    for(int i = 1; i<=N; i++){
        scanf("%d %d", &l, &r);
        int newRVal1 = xRAns + abs(xR-l) + abs(l-r);
        int newRVal2 = xLAns + abs(xL-l) + abs(l-r);
        if(newRVal1 <= newRVal2){
            newXRAns = newRVal1;
        } else {
            newXRAns = newRVal2;
        }

        int newLVal1 = xRAns + abs(xR-r) + abs(r-l);
        int newLVal2 = xLAns + abs(xL-r) + abs(r-l);

        if(newLVal1 <= newLVal2){
            newXLAns = newLVal1;
        } else {
            newXLAns = newLVal2;
        }   

        xRAns = newXRAns + 1;
        xLAns = newXLAns + 1;
        //cout<<xRAns<<","<<xLAns<<"\n";
        xR = r;
        xL = l;        
    }

    int ans1 = xRAns + N-xR;
    int ans2 = xLAns + N-xL;

    cout<<min(ans1, ans2)-1;
}