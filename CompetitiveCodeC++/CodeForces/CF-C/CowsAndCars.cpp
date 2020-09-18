#include <bits/stdc++.h>
using namespace std;

int main(){
    int nCows, nCars, nShow;
    while(cin >> nCows >> nCars >> nShow){
        int numDoors = nCows + nCars;
        double ans = 0;
        //If you choose cow originally
        ans += ((double) nCows/numDoors) * ((double) nCars/(numDoors - 1 - nShow));
        //If you choose car originally
        ans += ((double) nCars/numDoors) * ((double) (nCars - 1)/(numDoors - 1 - nShow));
        if(ans > 1){
            ans = 1;
        }
        printf("%.5f\n", ans);
    }
}