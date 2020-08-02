#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    if(n == 1 || n == 2){
        for(int a = 1; a<=100; a++){
            for(int b = 1; b<=100; b++){
                for(int c = 1; c<=100; c++){
                    if( a==b || a==c || b == c){
                        continue;
                    }
                    
                    if(pow(a, n) + pow(b, n) == pow(c, n)){
                        printf("%d %d %d\n", a, b, c);
                        return 0;
                    }
                }
            }
        }
    } else {
        printf("-1\n");
    }
}
