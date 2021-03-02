#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i<=t; i++){
        int n;
        scanf("%d", &n);
        double Eco = 1;
        double ev = 0;
        bool pos = false;
        while(n--){
            int x;
            double t;
            scanf("%d%lf", &x, &t);
            ev += t*abs(x);
            if(x < 0){
                Eco -= t;
            } else {
                pos = true;
            }
        }

        if(!pos){
            printf("Case %d: God! Save me\n", i);
        } else {
            ev /= Eco;
            printf("Case %d: %.2f\n", i, ev);
        }
    }
}