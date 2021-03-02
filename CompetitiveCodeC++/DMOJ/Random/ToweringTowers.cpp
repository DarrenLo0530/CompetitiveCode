#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


int main(){

  

    int n;
    scanf("%d", &n);

    stack<pii> st;
    for(int i = 0; i < n; i++){
        int h;
        scanf("%d", &h);

        if(i != 0){
            ans[i] = 1;
        }
        while(!st.empty() && st.top().first <= h){
            ans[i] += ans[st.top().second];
            st.pop();
        }

        
        st.push({h, i});
    }

    for(int i = 0; i<n; i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", ans[i]);
    }

    printf("\n");
}