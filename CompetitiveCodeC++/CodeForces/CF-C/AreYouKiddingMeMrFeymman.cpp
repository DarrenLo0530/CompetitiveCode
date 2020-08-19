#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    for(int i = 0; i<=100; i++){
        nums.push_back(i * i* i);
    }
    
    double n;
    while(true){
        scanf("%lf", &n);

        if(n == 0){
            break;
        }

        double a = (--upper_bound(nums.begin(), nums.end(), n)) - nums.begin();
        double ans = a + (double) (n - (double) (a * a * a))/(3 * a * a);
        printf("%.4f\n", ans);
    }
}