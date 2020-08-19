#include <bits/stdc++.h>
using namespace std;
typedef pair<char, char> pcc;
vector<vector<pcc>> cards;
bool matches(pcc a, pcc b){
    return a.first == b.first || a.second == b.second;
}

int main(){
    while(true){
        cards.clear();
        for(int i = 0; i<52; i++){
            char type, suit;
            cin >> type;
            if(type == '#'){
                return 0;
            }
            cin>>suit;
            vector<pcc> curr;
            curr.push_back({type, suit});
            cards.push_back(curr);
        }
        bool moveMade;

        while(true){
            moveMade = false;
            for(int i = 0; i<cards.size() && !moveMade; i++){
                for(int dist = 3; dist>=1 && !moveMade; dist-=2){
                    if(i-dist < 0){
                        continue;
                    }

                    if(matches(cards[i].back(), cards[i-dist].back())){
                        moveMade = true;
                        cards[i-dist].push_back(cards[i].back());
                        cards[i].pop_back();
                        if(!cards[i].size()){
                            cards.erase(cards.begin()  + i);
                        }
                    }
                }
                
            }

            if(!moveMade){
                break;
            }
        }
        if(cards.size() == 1){
            printf("%d pile remaining:", cards.size());
        } else {
            printf("%d piles remaining:", cards.size());
        }
        for(int i = 0; i<cards.size(); i++){
            cout<<" "<<cards[i].size();
        }

        cout<<"\n";
    }
}