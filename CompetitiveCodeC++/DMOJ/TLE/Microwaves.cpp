    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> pii;

    int main(){
        ll n, m, t;
        scanf("%lld%lld%lld", &n, &m, &t);

        vector<pii> people;
        multiset<ll> microwave;

        for(int i = 0; i<m; i++){
            ll t, f;
            scanf("%lld%lld", &t, &f);
            people.push_back({t, f});  
        }
        
        sort(people.begin(), people.end());
        for(int i = 0; i<n; i++){
            microwave.insert(0);
        }

        for(int i = 0; i<people.size(); i++){
            pii person = people[i];
            ll arrival = person.first;

            auto prevUsed = microwave.upper_bound(arrival);
            if(prevUsed != microwave.begin()){
                prevUsed--;
            }

            ll startTime = max(*prevUsed, arrival);
            if(startTime - *microwave.begin() >= t){
                cout<<*microwave.begin()<<'\n';
                return 0;
            }
            microwave.erase(prevUsed);
            microwave.insert(startTime + person.second);
        }

        cout<<*microwave.begin()<<'\n';
    }