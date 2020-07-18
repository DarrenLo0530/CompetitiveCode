    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);

        int numNegotiations = ceil((double)(a-c)/(-d-b));
        if(numNegotiations == 0){
            cout << a << '\n';
        } else if (a > c){
            cout << a << '\n';
        } else if (a + b*numNegotiations > c - d*(numNegotiations-1)){
            cout << c - d*(numNegotiations-1) << '\n';
        } else {
            cout << a + b*numNegotiations << '\n';
        }
    }