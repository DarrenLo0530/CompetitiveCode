#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> primeFac(int n){
    vector<pair<int, int>> ans;
    for(int i = 2; i*i <= n; i++){
        int cnt = 0;
    
        while(n % i == 0){
            cnt++;
            n/=i;
        }
        if(cnt != 0){
            ans.push_back({i, cnt});
        }

    }

    if(n != 1){
        ans.push_back({n, 1});
    }

    return ans;
}

bool solve(int m, int n){
    vector<pair<int, int>> p = primeFac(m);
    for(auto i: p){
        //Number of appearances of multiples of the prime between 1 and n
        //For example a multiple of 5 appears 6 times between 1 and 25(1, 5, 15, 20, 25(2))
        //25/5 = 5
        //5/5 = 1
        //1 + 5 = 6
        int numPrimes = 0;
        int tempN = n;
        while(tempN > 1){
            numPrimes += tempN/i.first;
            tempN/=i.first;
        }

        if(numPrimes < i.second){
            return false;
        }
    }

    return true;
}

int main(){
    int m, n;
    while(cin >> n >> m){
        if(solve(m, n)){
            printf("%d divides %d!\n", m, n);
        } else {
            printf("%d does not divide %d!\n", m, n);
        }
    }
}