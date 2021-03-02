#include <bits/stdc++.h>
using namespace std;
long double d[100001];
long double numFac[100001];
int main(){
    int n, p;
    scanf("%d%d", &n, &p);
    for(int i = 0; i<n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        d[i] = (r-l+1);
        numFac[i] = r/p - (l-1)/p;
    }

    long double ans = 0;

    //Ans is for each i
    //Probability that num[i] is divisble by p OR num[i] is NOT divisble by p AND num[i+1] is divisible by p;

    for(int i = 0; i<n; i++){
        int r = (i + 1) % n; 
        //Only take pair as curr index and next index, that way we don't long double count
        //Current num divisible by prime
        //Number of poss is number of ways i can be a number divisble by prime AND number of ways the other nums can be anything
        ans += 2000.0*numFac[i]/d[i];
        //Current num not divislble by prime but next number is
        //Number of poss is number of ways i can NOT be divisible by prime AND number of ways i+1 CAN be divisible by prime AND number of ways rest of numbers can be anything
        ans += 2000.0*(d[i] - numFac[i])*numFac[r]/(d[r] * d[i]);
    }

    printf("%.9Lf\n", ans);
}