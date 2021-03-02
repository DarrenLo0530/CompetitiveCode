#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int snowflake[12];
bool larger(vector<int> &v1, vector<int> &v2){
    if(v2.size() == 0){
        return true;
    }
    for(int i = 0; i<6; i++){
        if(v1[i] > v2[i]){
            return true;
        } else if(v2[i] > v1[i]){
            return false;
        }
    }
    return true;
}

vector<int> calculateMax(){
    vector<int> ans;
    for(int i = 0; i<6; i++){
        vector<int> curr;
        for(int j = 0; j<6; j++){
            curr.push_back(snowflake[i+j]);
        }

        if(larger(curr, ans)){
            ans = curr;
        }
    }

    return ans;
}

int main(){
    set<vector<int>> cnt;
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        for(int i = 0; i<6; i++){
            scanf("%d", snowflake + i);
            snowflake[i+6] = snowflake[i];
        }

        vector<int> ans = calculateMax();
        reverse(snowflake, snowflake + 12);
        vector<int> ans2 = calculateMax();
        if(larger(ans2, ans)){
            ans = ans2;
        }

        cnt.insert(ans);
    }

    if(cnt.size() == n){
        printf("No two snowflakes are alike.\n");
    } else {
        printf("Twin snowflakes found.\n");
    }
}