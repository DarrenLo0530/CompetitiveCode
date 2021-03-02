#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

char ans[105][105];
int a, b, c, d, n;
int x[27];

bool isValid(pii curr){
    if(!(curr.first >= 1 && curr.first <= a + c)){
        return false;
    }

    if(curr.first <= a){
        return curr.second >= 1 && curr.second <= b && ans[curr.second][curr.first] == '.';
    } else {
        return curr.second >= 1 && curr.second <= d && ans[curr.second][curr.first] == '.';
    }
}

int main(){
    printf("YES\n");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    for(int i = 0; i<105; i++){
        for(int j = 0; j<105; j++){
            ans[i][j] = '.';
        }
    }

    for(int i = 0; i<n; i++){
        scanf("%d", x + i);
    }

    int lr;
    pii start;
    if(d % 2 == 0){
        start = {a +1, d};
        lr = 1;
    } else {
        start = {a+c, d};
        lr = -1;
    }

    int curr = 0;
    int total = a*b + c*d;
    int ud = -1;
    while(total > 0){
        if(x[curr] == 0){
            curr++;
        }
        char c = 'a' + curr;
        ans[start.second][start.first] = c;
        total--;
        x[curr]--;
        if(start.second == 1){
            ud = 1;
        }
        
        pii next = {start.first + lr, start.second};
        if(!isValid(next) || (start.first == a + 1 && lr == -1 && start.second != 1) || (start.first == a && lr == 1)){
            lr = (lr == 1) ? -1 : 1;
            next = {start.first, start.second + ud};
        } 
        start = next;
    }

    for(int i = 1; i<=max(b, d); i++){
        for(int j = 1; j<=a+c; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
    
    
}