#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, l, r, sa, sk;
    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sa, &sk);

    if(n != k){
        int remStudents = n - k;
        int remScore = sa - sk;
        int remLeft = remScore % remStudents;
        int remAvg = remScore/remStudents;

        while(remStudents--){
            if(remLeft > 0){
                remLeft--;
                printf("%d ", remAvg + 1); 
            } else {
                printf("%d ", remAvg);
            }
        }

    }

    int exceeders = sk%k;
    int exceedAvg = sk/k;

    while(k--){
        if(exceeders > 0){
            printf("%d ", exceedAvg + 1);
            exceeders--;
        } else {
            printf("%d ", exceedAvg);
        }
    }
}