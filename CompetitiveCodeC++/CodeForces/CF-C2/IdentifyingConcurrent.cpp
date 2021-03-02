#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;


bool connected[1000][1000][1000];
string revAss[1000000];
map<string, int> ass;
vector<pair<int, int>> edges;
int main(){
    int cs = 0;
    
    int nc;
    while(cin >> nc && nc){
        memset(connected, false, sizeof(connected));
        ass.clear();
        edges.clear();

        int cnt = 0;
        for(int i = 0; i<nc; i++){
            int ne;
            scanf("%d", &ne);
            for(int j = 0; j<ne; j++){
                string e;
                cin >> e;

                revAss[cnt] = e;
                ass.insert({e, cnt});

                if(j != 0){
                    edges.push_back({cnt-1, cnt});
                }

                cnt++;
            }
        }

        int nm;
        scanf("%d", &nm);

        for(int i = 0; i<nm; i++){
            string a, b;
            cin >> a >> b;
            edges.push_back({ass[a], ass[b]});
        }

        for(pii i: edges){
            connected[0][i.first][i.second] = true;
        }

        for(int i = 0; i<cnt; i++){
            connected[0][i][i] = true;
        }

        for(int mid = 0; mid<cnt; mid++){
            for(int first = 0; first<cnt; first++){
                for(int second = 0; second<cnt; second++){
                    connected[mid+1][first][second] = connected[mid][first][second];
                    if(connected[mid][first][mid] && connected[mid][mid][second]){
                        connected[mid+1][first][second] = true;
                    }
                }
            }
        }

        vector<pair<string, string>> ans;
        for(int i = 0; i<cnt; i++){
            for(int j = i+1; j<cnt; j++){
                if(!connected[cnt][i][j] && !connected[cnt][j][i]){
                    ans.push_back({revAss[i], revAss[j]});
                }
            }
        }

        if(ans.size() == 0){
            printf("Case %d, no concurrent events.\n", ++cs, ans.size());
        } else {
            printf("Case %d, %d concurrent events:\n", ++cs, ans.size());
            for(int i = 0; i<min(2, (int) ans.size()); i++){
                cout << "(" << ans[i].first << "," << ans[i].second << ")";
                printf(" ");
            }
            printf("\n");
        }
    }
}