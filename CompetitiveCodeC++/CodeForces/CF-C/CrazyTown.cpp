#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct line{
    ll a, b, c;
};

ll x, y, x2, y2, n, la, lb, lc;
bool isIntersect(line a){
    ll determinant = (la*a.b - a.a*lb);
    if(determinant == 0){
        return false;
    }

    double xInt = (double) (lc*a.b - a.c*lb)/determinant;
    double yInt = (double) (a.c*la - lc*a.a)/determinant;
    return xInt >= min(x, x2) && xInt <= max(x, x2) && yInt >= min(y, y2) && yInt <= max(y, y2);
}

int main(){
    scanf("%lld%lld%lld%lld%lld", &x, &y, &x2, &y2, &n);
    la = (y2 - y);
    lb = (x - x2);
    lc = la*x + lb*y;

    int ans = 0;
    for(int i =0; i<n; i++){
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        line l = line{a, b, -c};
        if(isIntersect(l)){
            ans++;
        }
    }

    cout<<ans<<'\n';


}