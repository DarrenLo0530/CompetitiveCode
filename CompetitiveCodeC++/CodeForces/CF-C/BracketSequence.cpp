#include <bits/stdc++.h>
using namespace std;

int ans[100010];
int pos[100010];

int main(){
    int n;
    scanf("%d", &n);

    string left = "{[(<";
    string right = "}])>";

    for(int i = 1; i<=n; i++){
        memset(ans, 0, sizeof(ans));
        printf("Case %d:\n", i);

        string s;
        cin >> s;

        int posCounter = -1;
        for(int j = 0; j<s.size(); j++){
            if(left.find(s[j]) != string::npos){
                posCounter++;
                pos[posCounter] = j;
            } else {
                if(posCounter >= 0 && left.find(s[pos[posCounter]]) == right.find(s[j])){
                    int prevPos = pos[posCounter];
                    ans[prevPos] = j - prevPos + 1;
                    posCounter--;
                } else {    
                    posCounter = -1;
                }
            }

        }

        for(int x = s.size()-1 ; x>=0; x--){
            ans[x] += ans[x + ans[x]];
        }

        for(int x = 0; x<s.size(); x++){
            cout<<ans[x]<<'\n';
        }

    }
}