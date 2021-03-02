#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 4e4 + 10;
struct square {
    vector<int> sides;
};

map<int, vector<int>> sideLengths;
square squares[MX];

bool visited[100];
bool visiting[100];
set<int> adj[100];

bool solve(int x) {
    visiting[x+26] = true;

    for(int i: adj[x + 26]) {
        if(visiting[i + 26]) {
            return true;
        }

        if(!visited[i + 26] && solve(i)) {
            return true;
        }
    }

    visiting[x + 26] = false;
    visited[x + 26] = true;
    return false;
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = -26; i<=26; i++) {
        sideLengths.insert(make_pair(i, vector<int>()));
    }

    for(int i = 0; i<n; i++){
        vector<int> sides;
        for(int j = 0; j<4; j++) {
            int a;
            scanf("%d", &a);
            sides.push_back(a);
            sideLengths[a].push_back(i);
        }
    
        squares[i] = square {sides};
    }

    for(int i = -26; i<=26; i++) {
        if(i == 0) {
            continue;
        }
        for(int j : sideLengths[-i]) {
            bool prev = false;
            for(int k : squares[j].sides) {
                if(k == -i && !prev) {
                    prev = true;
                    continue;
                }

                adj[i + 26].insert(k);
            }
        }
    }
    
    
    for(int i = -26; i<=26; i++) {
        if(i == 0) {
            continue;
        }
        
        if(!visited[i+26] && solve(i)) {
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
}