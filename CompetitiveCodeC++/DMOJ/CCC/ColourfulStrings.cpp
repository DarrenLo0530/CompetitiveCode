    #include <bits/stdc++.h>
    using namespace std;

    #define INF 0x3f3f3f3f
    #define INFLL 0x3f3f3f3f3f3f3f3f
    #define PI 3.141592653589793

    typedef long long ll;
    typedef pair<int, int> pii;
    typedef pair<double, double> pdd;

    const int MX = 1e5 + 10;
    int cnt[26];
    const int md = 1e9 + 7;

    int main(){
        string s;
        cin >> s;
        for(int i = 0; i<s.size(); i++) {
            cnt[s[i] - 'a']++;
        }

        ll ans = 0;

        for(int i = 0; i<s.size(); i++) {
            int curr = s[i] - 'a';
            cnt[curr]--;

            ll temp = 1;
            for(int j = 0; j<26; j++) {
                if(curr == j) {
                    continue;
                }

                //Either we choose one of them
                temp *= (cnt[j]+1);
                temp %= md;

                //Or choose none
            }

            ans += temp;
            //cout << temp << "\n";
            ans %= md;
        }

        cout << (ans+1) % md << '\n';
    }