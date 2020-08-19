#include <bits/stdc++.h>
using namespace std;

int ans[1001][20000];
vector<pair<int, int>> formula[1001][20000];
int dfs(pair<int, int> curr){
    int ret = 0;
    if(formula[curr.second][curr.first].size() == 0){
        return ans[curr.second][curr.first];
    }

    for(auto i: formula[curr.second][curr.first]){
        ret += dfs({i.first, i.second});
    }

    formula[curr.second][curr.first].clear();
    ans[curr.second][curr.first] = ret;
    return ret;
}

pair<int, int> getCoord(string coord){
    int x = 0;
    for(int i = 0; i<coord.size(); i++){
        if(coord[i] >= 'A' && coord[i] <= 'Z'){
            x *= 26;
            x += coord[i] - 'A' + 1;
        } else {
            return {x - 1, stoi(coord.substr(i)) - 1};
        }
    }

    return {-1, -1};
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &m, &n);

        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                string a;
                cin>>a;
                if(a[0] == '='){
                    int prev = 1;
                    while(prev < a.size()){
                        int found = a.find('+', prev);
                        if(found == string::npos){
                            found = a.size();
                        }


                        formula[i][j].push_back(getCoord(a.substr(prev, found)));
                        prev = found + 1;
                    }



                } else {
                    ans[i][j] = stoi(a);
                }
            }
        }

        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(j != 0){
                    cout<<" ";
                }

                cout<<dfs({j, i});
            }
            cout<<'\n';
        }
    }
}