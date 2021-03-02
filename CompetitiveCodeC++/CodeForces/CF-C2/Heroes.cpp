#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int l[100][100];
vector<int> costs;

vector<vector<int>> grouping = {{}, {}, {}};
int minExp = INF;
int maxLiking = 0;
int liking(vector<int> &p){
    int liking = 0;
    for(int i = 0; i<p.size(); i++){
        for(int j = 0; j<p.size(); j++){
            liking += l[p[i]][p[j]];
        }
    }

    return liking;
}
void solve(int curr){
    if(curr == 7){
        
        int mx = 0;
        int mn = INF;
        for(int i = 0; i<3; i++){
            if(grouping[i].size() == 0){
                return;
            }
            mx = max(mx, costs[i]/(int)grouping[i].size());
            mn = min(mn, costs[i]/(int)grouping[i].size());
        }
        if(mx - mn < minExp){
            minExp = mx-mn;
            maxLiking = liking(grouping[0]) + liking(grouping[1]) + liking(grouping[2]);
        } else if(mx - mn == minExp){
            maxLiking = max(maxLiking, liking(grouping[0]) + liking(grouping[1]) + liking(grouping[2]));
        }
        return;
    }
    for(int i = 0; i<3; i++){
        grouping[i].push_back(curr);
        solve(curr + 1);
        grouping[i].erase(find(grouping[i].begin(), grouping[i].end(), curr));
    }   
}
int main(){
    int n;
    scanf("%d", &n);
    map<string, int> mp;
    mp["Anka"] = 0;
    mp["Chapay"] = 1;
    mp["Cleo"] = 2;
    mp["Troll"] = 3;
    mp["Dracul"] = 4;
    mp["Snowy"] = 5;
    mp["Hexadecimal"] = 6;

    for(int i =0 ; i<n; i++){
        string s, s2, s3;
        cin >> s >> s2 >> s3;
        l[mp[s]][mp[s3]] = 1;
    }
    for(int i = 0; i<3; i++){
        int x;
        scanf("%d", &x);
        costs.push_back(x);
    }

    solve(0);

    printf("%d %d\n", minExp, maxLiking);


}