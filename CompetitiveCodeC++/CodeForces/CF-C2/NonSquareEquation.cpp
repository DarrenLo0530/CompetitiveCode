#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    ll n;
    cin >> n;
    vector<ll> factors;

    int ans = INF;
    for(int i = 0; i< 100; i++){
        if(sqrt(i*i + 4*n) != (int)sqrt(i*i + 4*n)){
            continue;
        }
        double root1 = (-i + sqrt(i*i + 4*n))/2;
        double root2 = (-i - sqrt(i*i + 4*n))/2;
        if(root1 > 0 && root1 == (int) root1){
            int copy = root1;
            int sumDigits = 0;
            while(copy > 0){
                sumDigits += copy % 10;
                copy /= 10;
            }
            if(sumDigits == i){
                ans = min(ans, (int) root1);
            }
        }
        if(root2 > 0 && root2 == (int) root2){
            int copy = root2;
            int sumDigits = 0;
            while(copy > 0){
                sumDigits += copy % 10;
                copy /= 10;
            }
            if(sumDigits == i){
                ans = min(ans, (int) root2);
            }
        }
    }

    if(ans == INF){
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}