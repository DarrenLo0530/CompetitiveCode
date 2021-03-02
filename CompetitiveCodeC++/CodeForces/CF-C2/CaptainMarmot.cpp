#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 105;
pii m[MX], h[MX];

pii rotate(pii mole, pii home, int numRotations){
    pii copy = mole;
    copy.first -= home.first;
    copy.second -= home.second;
    for(int i = 0; i<numRotations; i++){
        copy = {-copy.second, copy.first};
    }

    copy.first += home.first;
    copy.second += home.second;
    return copy;
}
int sqr(int i){
    return i*i;
}

int dist(pii f, pii s){
    return sqr(f.first - s.first) + sqr(f.second - s.second);
}

bool formSquare(pii m1, pii m2, pii m3, pii m4){
    pii moles[] = {m1, m2, m3, m4};
    for(int i = 0; i<4; i++){
        for(int j = i+1; j<4; j++){
            if(dist(moles[i], moles[j]) == 0){
                return false;
            }
        }
    }

    int d1 = dist(m1, m2);
    int d2 = dist(m1, m3);
    int d3 = dist(m1, m4);


    if(d1 == d3){
        return d2 == (d1 + d3) && dist(m3, m2) == d1 && dist(m3, m4) == d1;
    } else if(d1 == d2){ 
        return d3 == (d1+d2) && dist(m3, m4) == d1 && dist(m4, m2) == d1;
    } else if(d2 == d3){
        return d1 == (d2 + d3) && dist(m2, m3) == d2 && dist(m2, m4) == d2;
    }

    return false;
}

int minRotations(){
    int ans = 2*INF;
    for(int i = 0; i<=3; i++){
        pii m1 = rotate(m[0], h[0], i);

        for(int j = 0; j<=3; j++){
            pii m2 = rotate(m[1], h[1], j);

            for(int k = 0; k<=3; k++){
                pii m3 = rotate(m[2], h[2], k);

                for(int l = 0; l<=3; l++){
                    pii m4 = rotate(m[3], h[3], l);
                    if(formSquare(m1, m2, m3, m4)){
                        ans = min(ans, i + j + k + l);
                    }
                }
            }
        }
    }
    
    return ans == 2*INF ? -1 : ans;
}

int main(){

    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<4; j++){
            int x, y, a, b;
            scanf("%d%d%d%d", &x, &y, &a, &b);
            m[j] = {x, y};
            h[j] = {a, b};
        }

        printf("%d\n", minRotations());
    }

}