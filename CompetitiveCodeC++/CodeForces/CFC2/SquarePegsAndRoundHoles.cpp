#include <bits/stdc++.h>
using namespace std;
int n;
double r;
typedef pair<double, double> pdd;
int isIn(pdd coord){
    if(pow(coord.first, 2) + pow(coord.second, 2) <= r){
        if(pow(coord.first+1, 2) + pow(coord.second+1, 2) <= r){
            return 0;
        }
        return 1;

    }
    return -1;
}
void solve(){
    int complete = 0, partial = 0;
    for(int i = 0; i<=150; i++){
        for(int j = 0; j<=150; j++){
            int res = isIn({i, j});
            if(res == 0){
                complete+=4;
            } else if(res == 1){
                partial+=4;
            }
        }
    }

    printf("In the case n = %d, %d cells contain segments of the circle.\n", n, partial);
    printf("There are %d cells completely contained in the circle.\n", complete);
}

int main(){
    int cnt = 0;
    while(cin >> n){
        r = pow((double)(2*n-1)/2, 2);
        if(cnt++ != 0){
            printf("\n");
        }
        solve();
    }

}