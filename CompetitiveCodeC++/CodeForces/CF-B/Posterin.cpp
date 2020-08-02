#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<int> buildings;

int main(){
    int n;

    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int d, h;
        scanf("%d%d", &d, &h);

        buildings.push_back(h);
    }

    stack<int> posterHeights;
    
    for(int height: buildings){
        if(posterHeights.empty()){
            ans++;
            posterHeights.push(height);
            continue;
        }

        if(height > posterHeights.top()){
            posterHeights.push(height);
            ans++;
        } else {
            while(!posterHeights.empty() && posterHeights.top() > height){
                posterHeights.pop();
            }

            if(posterHeights.empty() || posterHeights.top() != height){
                posterHeights.push(height);
                ans++;
            }
        }       
    }

    printf("%d\n", ans);
}