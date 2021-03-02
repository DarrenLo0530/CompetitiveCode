#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pair<pair<long, long>, int>> fruits;
int n;
void solve(ll totA, ll totO){
    printf("YES\n");
    
    ll oCnt1 = 0;
    for(int i = 0; i<2*n-1; i+=2){
        oCnt1 += fruits[i].first.second;
    }    
    if(oCnt1 >= (double)totO/2){
        for(int i = 0; i<2*n-1; i+=2){
            if(i != 0){
                printf(" ");
            }
            printf("%d", fruits[i].second);
        }
        printf("\n");
        return;
    }  

    for(int i = 1; i<2*n-1; i+=2){
        if(i != 1){
            printf(" ");
        }
        printf("%d", fruits[i].second);
    }
    printf(" %d\n", fruits[2*n-2].second);

}

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        fruits.clear();
        scanf("%d", &n);
        ll totA = 0, totO = 0;
        for(int i = 1; i<=2*n-1; i++){
            ll a, o;
            scanf("%lld%lld", &a, &o);
            totA += a;
            totO += o;
            fruits.push_back({{a, o}, i});
        }

        sort(fruits.begin(), fruits.end());

        solve(totA, totO);
        
    }
}