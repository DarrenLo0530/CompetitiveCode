#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> allFactors(int n){
    vector<pair<int, int>> ret;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            ret.push_back({n/i, i});
        }
    }

    return ret;
}
int main(){
    int n;
    while(cin >> n){
        vector<pair<int, int>> facs = allFactors(n*n);
        printf("%d\n", facs.size());
        

        for(int i = 0; i<facs.size(); i++){
            printf("1/%d = 1/%d + 1/%d\n", n, facs[i].first + n, facs[i].second + n);
        }

    }
}