#include <bits/stdc++.h>
using namespace std;

int locations[26];
vector<int> blocks[26];
int main(){
    int n;
    
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        locations[i] = i;
        blocks[i].push_back(i);
    }

    while(true){
        string command, modifier;
        int a, b;
        cin >> command;
        if(command == "quit"){
            break;
        }
        cin>>a>>modifier>>b;
        if(a == b || locations[a] == locations[b]){
            continue;
        }

        if(modifier == "onto"){
            auto first = find(blocks[locations[b]].begin(), blocks[locations[b]].end(), b) + 1;
            for(auto it = first; it != blocks[locations[b]].end(); it++){
                blocks[*it].push_back(*it);
                locations[*it] = *it;   
            }
            blocks[locations[b]].erase(first, blocks[locations[b]].end());
        }

        if(command =="move"){
            auto first = find(blocks[locations[a]].begin(), blocks[locations[a]].end(), a) + 1;
            for(auto it = first; it != blocks[locations[a]].end(); it++){
                blocks[*it].push_back(*it);
                locations[*it] = *it;   
            }
            blocks[locations[a]].erase(first, blocks[locations[a]].end());
            blocks[locations[a]].erase(--blocks[locations[a]].end());
            locations[a] = locations[b];
            blocks[locations[b]].push_back(a);
        } else {
            int aLoc = locations[a];
            auto first = find(blocks[aLoc].begin(), blocks[aLoc].end(), a);

            for(auto it = first; it != blocks[aLoc].end(); ++it){
                blocks[locations[b]].push_back(*it);
                locations[*it] = locations[b];  
            }

            blocks[aLoc].erase(first, blocks[aLoc].end());
        }
    }

    for(int i = 0; i<n; i++){
        printf("%d:", i);
        for(int j: blocks[i]){
            cout<<" "<<j;
        }

        cout<<'\n';
    }
}