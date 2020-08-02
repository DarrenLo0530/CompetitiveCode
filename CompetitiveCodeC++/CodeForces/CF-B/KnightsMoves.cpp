#include <bits/stdc++.h>
using namespace std;
pair<int, int> getLocation(string x){
    return {x[0] - 'a', x[1] - '0' - 1};
}


int main(){
    string a, b;
    while(cin >> a){
        cin >> b;

        set<pair<int, int>> visited;
        queue<pair<pair<int, int>, int>> toVisit;

        pair<int, int> x, y;
        x = getLocation(a);
        y = getLocation(b);


        visited.insert(x);
        toVisit.push({x, 0});

        while(!toVisit.empty()){
            pair<int, int> loc = toVisit.front().first;
            int moves = toVisit.front().second;
            toVisit.pop();

            if(loc == y){
                cout << "To get from " << a << " to " << b << " takes " << moves << " knight moves.\n";
                break;
            }

            for(int i = -2; i<=2; i++){
                for(int j = -2; j<=2; j++){
                    if(abs(i * j) == 2){
                        pair<int, int> nextLoc = {loc.first + i, loc.second + j};
                        if(!visited.count(nextLoc) && nextLoc.first >= 0 && nextLoc.second >= 0 && nextLoc.first < 8 && nextLoc.second < 8){
                            visited.insert(nextLoc);
                            toVisit.push({nextLoc, moves + 1});
                        }
                    }

                }
            }
        }
    }

}