#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a;
        scanf("%d", &a);
        if(360 % (180-a) == 0){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}