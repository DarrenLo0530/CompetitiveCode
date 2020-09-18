#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<ll> soldiers;
ll k[200001];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    ll prevSoldier = 0;
    for(int i = 0; i<n; i++){
        ll a;
        scanf("%lld", &a);
        prevSoldier += a;
        soldiers.push_back(prevSoldier);
    }

    for(int i = 0; i<q; i++){
        scanf("%lld", k + i);
    }
    
    ll arrows = 0;
    for(int i = 0; i<q; i++){
        arrows += k[i];
        auto first = upper_bound(soldiers.begin(), soldiers.end(), arrows);
        int numStanding = soldiers.end() - first;
        if(numStanding == 0){
            numStanding = n;
            arrows = 0;
        }
        printf("%d\n", numStanding);
    }
}