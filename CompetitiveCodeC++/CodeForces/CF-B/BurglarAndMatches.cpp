#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    int ans = 0;

    vector<pair<int, int>> boxes;

    for(int i = 0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        boxes.push_back(make_pair(b, a));
    }

    sort(boxes.begin(), boxes.end());
    reverse(boxes.begin(), boxes.end());

    //numMatches, numBoxes

    for(int i = 0; i<boxes.size(); i++){
        if(n == 0){
            break;
        }

        if(n >= boxes[i].second){
            n -= boxes[i].second;
            ans += boxes[i].second * boxes[i].first;
        } else {
            ans += n * boxes[i].first;
            n = 0;
        }
    }

    printf("%d", ans);
}