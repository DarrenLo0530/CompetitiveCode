#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int nums[100010];
ll psa[100010];
ll psa2[100010];
int main(){
    int n;
    scanf("%d", &n);

    vector<int> a;
    for(int i =0; i<n; i++){
        scanf("%d", nums+ i);
    }

    string s;
    cin >> s;

    for(int i = 0; i<n; i++){
        int prev = i == 0 ? 0 : psa[i-1]; 
        int prev2 = i == 0 ? 0 : psa2[i-1]; 

        psa[i] = prev;
        if(s[i] == '1'){
            psa[i] += nums[i];
        }
        psa2[i] = prev2 + nums[i];
    }


    ll ans = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '0'){
            continue;
        }
        if(i == 0){
            ans = max(ans, psa[n-1]);
            continue;
        }

        ans = max(ans, psa2[i-1] + psa[n-1] - psa[i]);
    }
    

    cout<<ans<<'\n';   
}