#include <bits/stdc++.h>
using namespace std;
int fib[205][101];

void addition(int n1, int n2){
    int newNum[101];
    for(int i = 0; i<100; i++){
        fib[n2+1][i+1] = (fib[n2+1][i] + fib[n1][i] + fib[n2][i])/10;

        fib[n2+1][i] = (fib[n2+1][i] + fib[n1][i] + fib[n2][i])%10;
    }
}

int main(){
    memset(fib, 0, sizeof(fib));
    
    fib[1][0] = 1;
    fib[2][0] = 1;

    for(int i = 1; i<=200; i++){
        addition(i, i+1);
    }

    int a;
    while(true){
        scanf("%d", &a);
        if(a == 0){
            break;
        }
        
        string ans = "";
        for(int i = 0; i<101; i++){
            char nextChar = '0' + fib[a][i];
            ans += nextChar;
            //cout<<fib[a][i]<<"\n";
        }
        reverse(ans.begin(), ans.end());


        int length = 0;
        while(ans[length] == '0'){
            length++;
        }

        ans.erase(0, length);

        cout<<ans<<"\n";
    }
}