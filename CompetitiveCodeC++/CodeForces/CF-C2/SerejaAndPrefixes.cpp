#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pair<int, pii>> stages;


vector<int> prefix;
int main(){
    int m;
    scanf("%d", &m);

    for(int i = 0; i<m; i++){
        int x;
        scanf("%d", &x);
        if(x == 1){
            int a;
            scanf("%d", &a);
            stages.push_back({1, {a, -1}});
            prefix.push_back(a);
        } else {
            int l, c;
            scanf("%d%d", &l, &c);
            stages.push_back({2, {l, c}});
            for(int j = 0; j<c && prefix.size() < 200000; j++){
                prefix.insert(prefix.end(), prefix.begin(), prefix.begin() + l);
            }
        }
    }

    ll currIdx = 0;
    int currStage = 0;
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        ll x;
        cin >> x;
        x--;
        if(i != 0){
            printf(" ");
        }
        while(currStage < stages.size()){
            if(stages[currStage].first == 1){
                if(currIdx++ == x){
                    printf("%d", stages[currStage].second.first);
                    currStage++;
                    break;
                }
                currStage++;
            } else {
                //cout << currIdx << '\n';
                int l = stages[currStage].second.first;
                int c = stages[currStage].second.second;
                if(x >= currIdx && x < currIdx + c*l){
                    int idx = (x - currIdx) % l;    
                    printf("%d", prefix[idx]);
                    break;
                } 

                currStage++;
                currIdx += c*l;
            }

        }
    }
}