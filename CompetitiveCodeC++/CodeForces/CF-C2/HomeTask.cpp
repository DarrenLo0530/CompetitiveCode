#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

char sComp[100005];
int sApp[100005];

int main(){
    set<pair<char, char>> bad;
    string s;
    cin >> s;
    int k;
    scanf("%d", &k);

    for(int i = 0; i<k; i++){
        string p;
        cin >> p;
        bad.insert({p[0], p[1]});
        bad.insert({p[1], p[0]});
    }

    sComp[0] = s[0];
    sApp[0] = 1;
    int currIdx = 0;
    for(int i = 1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            sApp[currIdx]++;
        } else {
            currIdx++;
            sComp[currIdx] = s[i];
            sApp[currIdx]++;
        }
    }

    int ans = 0;
    for(int i = 0; i<=currIdx; i++){
        if(bad.count({sComp[i], sComp[i+1]})){
            int j = i+2;
            while(j<=currIdx && sComp[j] == sComp[j-2]){
                j++;
            }

            int a1 = 0, a2 = 0;
            for(int c = i; c<j; c++){
                if(c % 2 == 0){
                    a1 += sApp[c];
                } else {
                    a2 += sApp[c];
                }
            }
            ans += min(a1, a2);
            i = j-1;
        } 
    }
    printf("%d\n", ans);
}