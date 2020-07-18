#include <bits/stdc++.h>
using namespace std;

vector<int> dists;

int cowsFit(int minDist){
    int numCows = 1;

    int currDist = 0;
    for(int i = 0; i<dists.size(); i++){
        currDist += dists[i];
        if(currDist >= minDist){
            numCows++;
            currDist = 0;
        }
    }
    return numCows;
}

int search(int l, int r, int numCows){
    if(l == r){
        return l;
    }


    int mid = (l+r+1)/2;
    int c = cowsFit(mid);
    if(c >= numCows){
        return search(mid, r, numCows);
    } else {
        return search(l, mid-1, numCows);
    }
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        dists.clear();
        int n, c;
        scanf("%d%d", &n, &c);

        vector<int> stalls;

        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            stalls.push_back(x);
        }

        sort(stalls.begin(), stalls.end());
        int maxDist = stalls[stalls.size() - 1];
        for(int i = 1; i<stalls.size(); i++){
            dists.push_back(stalls[i] - stalls[i-1]);
        }



        int ans = search(1, maxDist, c);
        printf("%d\n", ans);
    }
}