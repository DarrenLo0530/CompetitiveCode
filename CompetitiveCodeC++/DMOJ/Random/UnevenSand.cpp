#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    ll l = 1;
    ll r = 2e9;
    while(l <= r){
        int mid = (l + r)/2;
        cout << mid << endl;
        string response;
        cin >> response;
        if(response == "OK"){
            break;
        } else if(response == "FLOATS"){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
}