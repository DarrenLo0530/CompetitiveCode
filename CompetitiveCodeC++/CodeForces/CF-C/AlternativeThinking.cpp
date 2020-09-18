#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    int n;
    scanf("%d", &n);
    cin >> s;


    int totalcnt = 1;
    int curr = s[0] - '0';
    for(int i = 1; i< n; i++){
        if(s[i] - '0' == 1 - curr){
            totalcnt++;
            curr = 1 - curr;

        }
    }

    


    printf("%d\n", min(n, totalcnt + 2));
    





}