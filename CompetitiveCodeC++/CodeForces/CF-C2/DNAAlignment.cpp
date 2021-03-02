#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    const int m = 1e9 + 7;

    ll n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    int a = count(s.begin(), s.end(), 'A');
    int c = count(s.begin(), s.end(), 'C');
    int g = count(s.begin(), s.end(), 'G');
    int t = count(s.begin(), s.end(), 'T');
    int cnt = 0;
    int mx = max(max(a, c), max(g, t));

    if(a == mx) cnt++;
    if(c == mx) cnt++;
    if(g == mx) cnt++;
    if(t == mx) cnt++;

    ll ans = 1;
    for(int i = 0; i<n; i++){
        ans = (ans * cnt) % m;
    }

    printf("%lld\n", ans);

    

}