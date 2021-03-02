#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 2e5+10;

const ll md = 998244353LL;

void add(bitset<MX> &ba, bitset<MX> bb) {
    int c = 0;

    for(int i = 0; i<MX; i++) {
        int a = ba.test(i);
        int b = bb.test(i);
        ba.set(i, a ^ b ^ c);
        c = ((a & b) | (a & c) | (b & c));
    }
}

ll mods[MX];
void bmod() {
    ll mod = 1;
    for(int i = 0; i<MX; i++) {
        mods[i] = mod;
        mod *= 2;
        mod %= md;
    }
}


int psa[MX+2];

int main(){
    bmod();
    int n, m;
    scanf("%d%d", &n, &m);
    string a, b;
    cin >> a >> b;

    bitset<MX> ba(a);
    bitset<MX> bb(b);

    for(int i = MX-1; i>=0; i--) {
        psa[i] = psa[i+1];
        psa[i] += bb.test(i); 
    }

    ll ans = 0;
    for(int i = 0; i<MX; i++) {
        if(ba.test(i)) {
            ans += (psa[i] * mods[i]) % md;
            ans %= md;
        }
    }
    
    cout << ans << '\n';
}