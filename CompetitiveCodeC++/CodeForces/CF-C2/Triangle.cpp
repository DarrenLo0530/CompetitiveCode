#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pii> nums[2000001];
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i = 1; i<=1000; i++){
        for(int j = i; j<=1000; j++){
            nums[i*i + j*j].push_back({i, j});
            nums[i*i + j*j].push_back({j, i});
        }
    }

    
    pii p1, p2, p3;
    for(int i = 0; i<nums[a*a].size(); i++){
        for(int j = 0; j<nums[b*b].size(); j++){
            p2 = {p1.first + nums[a*a][i].first, p1.second - nums[a*a][i].second};
            p3 = {p2.first + nums[b*b][j].first, p2.second + nums[b*b][j].second};
            if(p3.first * p3.first + p3.second * p3.second == a*a + b*b && p3.first != 0 && p3.second != 0){
                printf("YES\n");
                printf("%d %d\n", p1.first, p1.second);
                printf("%d %d\n", p2.first, p2.second);
                printf("%d %d\n", p3.first, p3.second);
                return 0;
            }
        }
    }
    cout << "NO\n";

}