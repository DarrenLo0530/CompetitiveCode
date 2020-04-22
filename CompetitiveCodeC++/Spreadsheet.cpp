#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<pi> grid[10][10];
int ans[10][10];
bool hasNum[10][10];

map<int, int> mp;

bool isNum(string word){
    for(int i = 0; i<word.length(); i++){
        if(!(word[i] >= '0' && word[i] <= '9')){
            return false;
        }
    }
    return true;
}

vector<pi> getCoords(string word){
    vector<pi> ret;
    int idx = 0;
    while(idx < word.length()){
        int y = word[idx] - 'A';
        int x = (word[idx+1] - '0') - 1;
        ret.push_back(make_pair(x, y));
        idx += 3;
    }

    return ret;
}

int main(){
    string a;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<9; j++){
            cin>>a;
            if(isNum(a)){
                ans[i][j] = stoi(a);
                hasNum[i][j] = true;
            } else {
                grid[i][j] = getCoords(a);
            }
        }
    }

    for(int k = 0; k<100; k++){
        for(int i = 0; i<10; i++){
            for(int j = 0; j<9; j++){
                for(auto it = grid[i][j].begin(); it != grid[i][j].end(); ++it){
                    if(hasNum[it->second][it->first]){
                        ans[i][j] += ans[it->second][it->first];
                        grid[i][j].erase(it);
                        it--;
                    }
                }
                if(grid[i][j].size() == 0){
                    hasNum[i][j] = true;
                }
            }
        }
    }

    for(int i = 0; i<10; i++){
        for(int j = 0; j<9; j++){
            if(hasNum[i][j]){
                cout<<ans[i][j]<<" ";
            } else {
                cout<<"* ";
            }
        }
        cout<<'\n';
    }
}