#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<int> ans;
int tp[10];
int a;
string b;
void construct(int curr, int pow, string lucky){
    if(lucky == b){
        ans.push_back(curr);
    }

    if(pow >= 6){
        return;
    }

    for(int i = 0; i<10; i++){
        string copy = lucky;
        if(i == 4){
            copy = "4" + copy;
        }
        if(i == 7){
            copy = "7" + copy;
        }

        construct(i*tp[pow] + curr, pow+1, copy);
    }
}
int main(){
    
    cin >> a >> b;

    tp[0] = 1;
    for(int i = 1; i<10; i++){
        tp[i] = tp[i-1]*10;
    }

    construct(0, 0, "");

    sort(ans.begin(), ans.end());
    printf("%d\n", *upper_bound(ans.begin(), ans.end(), a));
}