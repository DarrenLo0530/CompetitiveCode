#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> parts[1001];
int prevPart[1001];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){

        for(int i = 0; i<1001; i++){
            parts[i].clear();
        }

        int counter = 0;
        map<string, int> types;
        int n, b;
        scanf("%d%d", &n, &b);

        for(int i = 0; i<n; i++){
            string t, n;
            int p, q;
            cin >> t >> n >> p >> q;
            if(types.find(t) == types.end()){
                types[t] = counter;
                counter++;
            }

            parts[types[t]].push_back({q, p});
        }

        int l = 0, r = 1000000000, mid;
        while(l <= r){
            mid = (l + r)/2;
            int totalCost = 0;

            bool boughtAll = true;
            for(int i = 0; i<counter; i++){
                bool bought = false;
                int minPartCost = 0x3f3f3f3f;
                for(auto p: parts[i]){
                    if(p.first >= mid){
                        bought = true;
                        minPartCost = min(minPartCost, p.second);
                    }
                }
                boughtAll &= bought;
                totalCost += minPartCost;
            }
            
            if (totalCost <= b && boughtAll){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout<<r<<'\n';

    }
    


}