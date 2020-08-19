#include <bits/stdc++.h>
using namespace std;
vector<int> locs[300001];
bool unread[300001];
int n, q;

int main(){
    scanf("%d%d", &n, &q);

    int prev = 0;
    int cnt = 0;
    int totalUnread = 0;
    for(int i = 0; i<q; i++){
        int t, x;
        scanf("%d%d", &t, &x);

        if(t == 1){
            totalUnread++;
            locs[x].push_back(cnt);
            unread[cnt] = true;
            cnt++;
        } else if(t == 2){
            for(int location: locs[x]){
                if(unread[location]){
                    unread[location] = false;
                    totalUnread--;
                }
            }
            locs[x].clear();
        } else {
            while(prev < x){
                if(unread[prev]){
                    unread[prev] = false;
                    totalUnread--;
                }
                ++prev;
            }
        }

        printf("%d\n", totalUnread);
    }
}