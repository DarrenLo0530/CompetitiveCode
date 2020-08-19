#include <bits/stdc++.h>
using namespace std;

int dist(int s, int e, int c){
    return min(abs(s - e), c - abs(s - e));
}
int main(){
    int n, p;
    scanf("%d%d", &n, &p);
    p--;

    string s;
    cin >> s;

    int l = 0x3f3f3f3f, r = 0;
    int ans = 0;
    for(int i = 0; i <= (n-1)/2; i++){
        if(s[i] != s[s.size() - 1 - i]){
            l = min(l, i);
            r = max(r, i);
        }
        ans += dist(s[i] - 'a', s[s.size() - 1- i] - 'a', 26);
    }

    if(l == 0x3f3f3f3f){
        cout<<0<<'\n';
        return 0;
    }
    if(p >= n/2){
        p = n - p - 1;
    }

    ans += min(abs(l - p), abs(r - p)) + abs(l - r);
    cout<<ans<<'\n';

}