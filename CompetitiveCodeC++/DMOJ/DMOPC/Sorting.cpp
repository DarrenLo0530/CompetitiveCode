#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int a[1000001];

int n;

bool solve(){
    for(int i = 0; i<n-1; i++){
        if(!a[i]){
            continue;
        }

        int j;
        for(j = i+1; j<n; j++){
            if(!a[j]){
                continue;
            }
            
            if(a[j] < a[i]){
                return false;
            }

            break;
        }
        i = j-1;

        
    }

    int l = 0, r = n-1;
    while(a[l] != 0){
        l++;
    }
    while(a[r] != 0){
        r--;
    }

    int prev = -1;
    for(int i = l+1; i<r; i++){
        if(!a[i]){
            continue;
        }

        if(prev == -1){
            prev = a[i];
        } 

        if(a[i] != prev){
            return false;
        }
    }
    return true;

    
}
int main(){
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%d", a + i);
    }

    if(solve()){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}