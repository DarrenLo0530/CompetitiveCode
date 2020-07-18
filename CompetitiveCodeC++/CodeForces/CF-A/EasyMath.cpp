#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ull get_lcm(ull a, ull b){
    return a*b/__gcd(a, b);
}

ll getNumberDivisible(ll st, ll nd, ull num){
    int start = ceil((double)st/num);
    int end = nd/num;
    return end - start + 1;
}

ll groups[6];

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        fill(groups, groups+6, 0ll);

        ll n, m, a, d;
        scanf("%lld%lld%lld%lld", &n, &m, &a, &d);
        vector<ll> nums = {a, a+d, a+2*d, a+3*d, a+4*d};

        for(int i = 1; i<(1<<5); i++){
            bitset<6> num (i);
            int numSet = num.count();
            
            ull lcm = 1;
            for(int i = 0; i<=4; i++){
                if(num.test(i)){
                    lcm = get_lcm(nums[i], lcm);
                }
            }
            
            ll numDivisible = getNumberDivisible(n, m, lcm);
            //Inclusion exclusion pri    nciple for calculating (A OR B OR C OR D)
            //Excludes any duplicates
            //Counting number divisible by A OR B OR C OR D, then subtracting from total to get opposite
            if(numSet % 2 == 1){
                groups[numSet] += numDivisible;
            } else {
                groups[numSet] -= numDivisible;
            }
        }

        ll ans = m - n + 1;
        for(ll i: groups){
            ans -= i;
        }
        cout << ans << '\n';
    }
}