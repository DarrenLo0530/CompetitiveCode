#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int nfreq[26], hfreq[26];
ll p = 31;
ll mod1 = 1e9 + 7;
ll mod2 = 1e9 + 9;

set<pair<ll, ll>> usedWords;

ll expMod(ll x, ll p, ll mod) {
    ll ans = 1;
    while(p > 0) {
        if(p % 2 != 0) {
            ans = (ans * x) % mod;
        }

        x = (x * x) % mod;
        p /= 2;
    }

    return ans;
}

ll addLetter(ll hash, ll mod, char letter) {
    hash = (hash * p) % mod;
    hash = (hash + (letter - 'a' + 1)) % mod;

    return hash;
}

ll removeLetter(ll hash, ll remMod, ll mod, char letter) {
    return (hash - (remMod * (letter - 'a' + 1)) % mod + mod) % mod;
}

string n, h;
ll remMod1, remMod2;

bool checkEquality(int arr1[], int arr2[]) {
    for(int i = 0; i<26; i++) {
        if(arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    if(n.size() > h.size()) {
        return;
    }

    for(char c : n) {
        nfreq[c - 'a']++;
    }


    ll hash1 = 0;
    ll hash2 = 0;

    for(int i = 0; i<n.size(); i++) {
        hfreq[h[i] - 'a']++;
        hash1 = addLetter(hash1, mod1, h[i]);
        hash2 = addLetter(hash2, mod2, h[i]);

    }
    
    for(int i = n.size(); i<=h.size(); i++) {
        if(checkEquality(nfreq, hfreq)) {
            usedWords.insert(make_pair(hash1, hash2));
        }

        if(i < h.size()) {
            hfreq[h[i - n.size()] - 'a']--;
            hfreq[h[i] - 'a']++;

            hash1 = removeLetter(hash1, remMod1, mod1, h[i - n.size()]);
            hash1 = addLetter(hash1, mod1, h[i]);   

            hash2 = removeLetter(hash2, remMod2, mod2, h[i - n.size()]);
            hash2 = addLetter(hash2, mod2, h[i]);      
        }
    }
}

int main(){
    cin >> n >> h;

    remMod1 = expMod(p, n.size()-1, mod1);
    remMod2 = expMod(p, n.size()-1, mod2);

    solve();
    cout << usedWords.size() << '\n';
}