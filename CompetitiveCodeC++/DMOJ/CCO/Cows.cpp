#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int N, x, y;
int INF = 0x3f3f3f3f;

pi trees[10001];
vector<pi> usedTrees;
pi pa = make_pair(INF, INF);
int paIdx = 0;
int N2 = 1;

int getOrientation(pi p0, pi p1, pi p2){
    int p = (p1.second - p0.second) * (p2.first - p1.first) - (p1.first - p0.first) * (p2.second - p1.second);
    //+ = clockwise
    //- = counterclockwise
    //0 = normal
    return p;
}

int getDist(pi p1, pi p2){
    return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2); 
}

bool compare(pi& p1, pi& p2){
    int o = getOrientation(pa, p1, p2);
    if(o > 0){
        return false;
    } else if(o < 0){
        return true;
    } else {
        return getDist(pa, p1) <= getDist(pa, p2);
    }
}

pi getSecondNext(stack<pi> &s){
    pi top = s.top();
    s.pop();
    pi ans = s.top();
    s.push(top);
    return ans;
}

void getTrees(){
    stack<pi> s;
    s.push(trees[0]);
    s.push(trees[1]);
    s.push(trees[2]);

    for(int i = 3; i<N2; i++){
        while(getOrientation(getSecondNext(s), s.top(), trees[i]) > 0){
            s.pop();
        }
        s.push(trees[i]);
    }

    while(!s.empty()){
        usedTrees.push_back(s.top());
        s.pop();
    }
}

int calculateCows(){
    int ans = 0;
    for(int i = 0; i<usedTrees.size(); i++){
        int k = (i+1)%usedTrees.size();
        ans += usedTrees[i].first*usedTrees[k].second - usedTrees[k].first*usedTrees[i].second;
    }

    return abs(ans/100);
}

int main(){
    for(int i = 0; i<10001; i++){
        trees[i] = make_pair(INF, INF);
    }
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d %d", &x, &y);
        trees[i] = pi{x, y};
    }

    for(int i = 0; i<N; i++){
        if(trees[i].second < pa.second || (trees[i].second == pa.second && trees[i].first < pa.first)){
            pa = trees[i];
            paIdx = i;
        }
    }
    swap(trees[0], trees[paIdx]);
    sort(trees+1, trees+N, compare);
    

    //Removes points so that only the furthest one remains if multiple points are colinear
    for(int i = 1; i<N; i++){
        while(i < N-1 && getOrientation(pa, trees[i], trees[i+1]) == 0){
            //If it isnt a left turn, then there is a more efficient path
            i++;
        }
        trees[N2] = trees[i];
        N2++;
    }

    if(N2 < 3){
        return 0;
    }

    getTrees();
    cout<<calculateCows();  
    



}