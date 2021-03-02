#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


bool isConnected[20][20];
pair<pii, pii> straws[20];

bool isInStraw(double x, double y, int straw){
    return x >= min(straws[straw].first.first, straws[straw].second.first) && 
           x <= max(straws[straw].first.first, straws[straw].second.first) && 
           y >= min(straws[straw].first.second, straws[straw].second.second) && 
           y <= max(straws[straw].first.second, straws[straw].second.second);
}

bool intersects(int straw1, int straw2){
    int a1 = straws[straw1].first.second - straws[straw1].second.second;
    int b1 = straws[straw1].second.first - straws[straw1].first.first;
    int c1 = a1*straws[straw1].first.first + b1*straws[straw1].first.second;

    int a2 = straws[straw2].first.second - straws[straw2].second.second;
    int b2 = straws[straw2].second.first - straws[straw2].first.first;
    int c2 = a2*straws[straw2].first.first + b2*straws[straw2].first.second;

    if(b1*a2 - a1*b2 == 0){
        return min(straws[straw1].first.second, straws[straw1].second.second) <=
               max(straws[straw2].first.second, straws[straw2].second.second) && 
               min(straws[straw2].first.second, straws[straw2].second.second) <=
               max(straws[straw1].first.second, straws[straw1].second.second) && 
               min(straws[straw1].first.first, straws[straw1].second.first) <=
               max(straws[straw2].first.first, straws[straw2].second.first) && 
               min(straws[straw2].first.first, straws[straw2].second.first) <=
               max(straws[straw1].first.first, straws[straw1].second.first);
       
    } else {
        double x = (c2*b1 - c1*b2)/(double)(b1*a2 - a1*b2);
        double y = (c1*a2 - c2*a1)/(double)(b1*a2 - a1*b2);

        return isInStraw(x, y, straw1) && isInStraw(x, y, straw2);
    }
}


int main(){

    int t;
    scanf("%d", &t);

    for(int x = 0; x<t; x++){
        memset(isConnected, 0, sizeof(isConnected));

        int n;
        scanf("%d", &n);
        for(int i = 1; i<=n; i++){
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            straws[i] = {{x1, y1}, {x2, y2}};
        }

        for(int i = 1; i<=n; i++){
            isConnected[i][i] = true;
            for(int j = i+1; j<=n; j++){
                isConnected[i][j] = isConnected[j][i] = intersects(i, j);
            }
        }
        

        for(int mid = 1; mid<=n; mid++){
            for(int first = 1; first<=n; first++){
                for(int second = 1; second<=n; second++){
                    isConnected[first][second] |= isConnected[first][mid] && isConnected[mid][second];
                }
            }
        }


        if(x != 0){
            printf("\n");
        }
        int a, b;
        while(cin >> a >> b){
            if(!a && !b){
                break;
            }
            if(isConnected[a][b]){
                printf("CONNECTED\n");
            } else {
                printf("NOT CONNECTED\n");
            }
        }

    }

    
}