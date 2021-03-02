#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<int> a;
set<int> used;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(cnt >= k){
            return 0;
        }
        cnt++;
        printf("%d %d\n", 1, a[i]);
    }

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(cnt >= k){
                return 0;
            }
            cnt++;
            cout << i+2 << " ";
            for(int l = 0; l<=i; l++){
                cout << a[l] << " ";
            }
            cout << a[j] << "\n";
        }
    }
}   