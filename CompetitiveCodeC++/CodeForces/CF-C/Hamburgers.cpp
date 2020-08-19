#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll store[3], burger[3], has[3];

int main(){
    string s;
    cin >> s;

    burger[0] = count(s.begin(), s.end(), 'B');
    burger[1] = count(s.begin(), s.end(), 'S');
    burger[2] = count(s.begin(), s.end(), 'C');

    for(int i = 0; i<3; i++){
        cin >> has[i];
        if(burger[i] == 0){
            has[i] = 0;
        }
    }

    for(int i = 0; i<3; i++){
        cin >> store[i];
    }

    ll r;
    cin >> r;

    ll ans = 0x3f3f3f3f;

    for(int i = 0; i<3; i++){
        if(burger[i] != 0){
            ans = min(ans, has[i]/burger[i]);
        }
    }

    for(int i = 0; i<3; i++){
        has[i] -= ans * burger[i];
    }

    while(has[0] != 0 || has[1] != 0 || has[2] != 0){
        for(int i = 0; i<3; i++){
            if(has[i] < burger[i]){
                r -= (burger[i] - has[i]) * store[i];
                has[i] = burger[i];
            }
        }

        for(int i = 0; i<3; i++){
            has[i] -= burger[i];
        }

        if(r < 0){
            cout<<ans<<'\n';
            return 0;
        }

        ans++;
    }
    
    ans += r/(store[0] * burger[0] + store[1] * burger[1] + store[2] * burger[2]);
    cout<<ans<<'\n';
}