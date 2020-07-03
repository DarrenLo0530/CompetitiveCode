#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, h;
    scanf("%d%d", &n, &h);

    int width = n;
    for(int i = 0; i<n; i++){
        int currHeight;
        scanf("%d", &currHeight);

        if(currHeight > h){
            width++;
        }
    }

    cout << width << '\n';
}