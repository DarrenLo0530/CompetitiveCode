#include <bits/stdc++.h>
using namespace std;
int main(){
    int T, N, M;
    string name;
    int quantity, price;
    cin>>T;


    for(int t = 0; t<T; t++){
        map<string, vector<pair<int, int>>> items;
        cin>>N;

        for(int i = 0; i<N; i++){
            cin>>M;
            for(int j = 0; j<M; j++){
                cin>>name>>price>>quantity;
                if(items.find(name) != items.end()){
                    items.at(name).push_back(make_pair(price, quantity));
                } else {
                    vector<pair<int, int>> temp;
                    temp.push_back(make_pair(price, quantity));
                    items.insert(make_pair(name, temp));
                }
            }
        }

        int ans = 0;
        int K;
        cin>>K;
        for(int i = 0; i<K; i++){
            cin>>name>>quantity;
            sort(items.at(name).begin(), items.at(name).end());

            for(auto item: items.at(name)){
                if(quantity == 0){
                    break;
                }
                if(item.second > quantity){
                    ans += item.first*quantity;
                    quantity = 0;
                } else {
                    ans += item.first*item.second;
                    quantity -= item.second;
                }
            }
        }

        cout<<ans<<"\n";
    }
}