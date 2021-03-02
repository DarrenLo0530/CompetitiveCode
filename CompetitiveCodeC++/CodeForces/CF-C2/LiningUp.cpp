#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 1000;
struct line {
    pii m;
    pii b;

    bool operator< (const line &l1) const {
        if(m == l1.m){
            return b < l1.b;
        }
        return m < l1.m;
    }
};

int x[MX], y[MX];

pii reduce(pii frac){
    int g = __gcd(frac.first, frac.second);
    return {frac.first/g, frac.second/g};
}

line createLine(int x1, int y1, int x2, int y2){
    if(y1 < y2){
        swap(y1, y2);
        swap(x1, x2);
    }

    pii m = reduce({y1 - y2, x1 - x2});
    pii b = reduce({y1*m.second - m.first*x1, m.second});
    return line{m, b};
}



int main(){
    int n;
    string s;
    scanf("%d", &n);
    getline(cin, s);
    getline(cin, s);
    for(int c = 0; c<n; c++){


        int t;
        for(t = 0; getline(cin, s) && !s.empty(); t++){
            stringstream ss(s);
            ss >> x[t] >> y[t];
        }        

        int ans = 0;
        for(int i = 0; i<t; i++){
            map<line, int> mp;
            for(int j = i+1; j<t; j++){
                line l = createLine(x[i], y[i], x[j], y[j]);
                if(mp.find(l) == mp.end()){
                    mp[l] = 2;
                } else {
                    mp[l]++;
                }

                ans = max(ans, mp[l]);
            }
        }

        if(c != 0){
            printf("\n");
        }
        printf("%d\n", ans);

    }
}