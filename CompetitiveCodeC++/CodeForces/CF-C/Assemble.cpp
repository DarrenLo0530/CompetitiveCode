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

        for(int i = 0; i<counter; i++){
            sort(parts[i].begin(), parts[i].end());
            reverse(parts[i].begin(), parts[i].end());
        }

        int quality = 0x3f3f3f3f;
        int price = 0;
        for(int i = 0; i<counter; i++){
            price += parts[i][0].second;
            prevPart[i] = parts[i][0].second;
            quality = min(quality, parts[i][0].first);
        }

        while(price > b){
            int partRemoveType = 0;
            int newPrice = 0;
            int newQuality = 0;
            for(int i = 0; i<counter; i++){
                for(int j = 0; j<parts[i].size(); j++){
                    //Cheaper than previous part in same type and higher quality than previiously changed part
                    if(parts[i][j].second < prevPart[i] && parts[i][j].first > newQuality){
                        newPrice = parts[i][j].second;
                        newQuality = parts[i][j].first;
                        partRemoveType = i;
                        break;
                    }
                }
            }

            price -= prevPart[partRemoveType] - newPrice;
            prevPart[partRemoveType] = newPrice;
            quality = min(quality, newQuality);
        }

        cout<<quality<<'\n';
    }
    


}