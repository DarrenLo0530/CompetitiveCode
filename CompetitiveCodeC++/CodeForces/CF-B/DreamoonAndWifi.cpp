#include <bits/stdc++.h>
using namespace std;

struct Message{
    int p, n, q;
};

Message msg(string s){
    Message ret = {0, 0, 0};
    for(char i: s){
        if(i == '+'){
            ret.p++;
        } else if(i == '-'){
            ret.n++;
        } else {
            ret.q++;
        }
    }

    return ret;
}

int factorial(int n){
    if(n == 0){
        return 1;
    }

    for(int i = n-1; i>=1; i--){
        n*= i;
    }

    return n;
}

int nChooseK(int n, int k){
    return factorial(n)/ (factorial(k) * factorial(n-k));
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    Message m1 = msg(s1);
    Message m2 = msg(s2);

    int pNeeded;
    double ans = 0;

    if(!(m2.p > m1.p || m2.n > m1.n)){
        pNeeded = m1.p - m2.p;
        ans = pow(0.5, m2.q);
        ans *= nChooseK(m2.q, pNeeded);
    }

    printf("%.10f", ans);

}