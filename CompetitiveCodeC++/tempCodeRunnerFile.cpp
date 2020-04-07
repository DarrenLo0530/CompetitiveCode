#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct dat{
    int firstIdx, lastIdx;
};

int main(){
    int N, l;
    scanf("%d", &N);

    for(int i = 0; i<N; i++){
        unordered_map<int, dat> mp1;
        unordered_map<int, dat> mp2;
        scanf("%d", &l);

        int curr, prev = INF;

        for(int j = 0; j<l; j++){
            scanf("%d", &curr);
            if(curr != prev || j == 0){
                mp1.insert(make_pair(curr, dat{j, 0}));
                if(mp1.find(prev) != mp1.end()){
                    mp1.at(prev).lastIdx = j-1;
                }
            }
            if(j == l-1){
                mp1.at(curr).lastIdx = j;
            }
            prev = curr;
        }

        prev = INF;
        for(int j = 0; j<l; j++){
            scanf("%d", &curr);
            if(curr != prev || j == 0){
                mp2.insert(make_pair(curr, dat{j, 0}));
                if(mp2.find(prev) != mp1.end()){
                    mp1.at(prev).lastIdx = j-1;
                }
            }
            if(j == l-1){
                mp2.at(curr).lastIdx = j;
            }
            prev = curr;
        }
        int dist = 0;

        for(auto it = mp1.begin(); it!=mp1.end(); ++it){
            int key = it->first;
            if(mp2.find(key) != mp2.end()){
                int dist1 = abs(mp1.at(key).firstIdx - mp2.at(key).lastIdx);
                int dist2 = abs(mp2.at(key).firstIdx - mp1.at(key).lastIdx);
                dist = max(max(dist, dist1), dist2);
            }
        }
        printf("The maximum distance is %d\n", dist);
    }
}