#include <bits/stdc++.h>
using namespace std;

int zeroCount[200005];
int oneCount[200005];
int main(){
    string a, b;

    long long ans = 0;
    cin >> a>> b;
    for(int i = 1; i<=b.size(); i++){
        oneCount[i] = oneCount[i-1];
        zeroCount[i] = zeroCount[i-1];

        if(b[i-1] == '0'){
            zeroCount[i]++;
        } else {
            oneCount[i]++;
        }
    }

    for(int i = 0; i<a.size(); i++){
        if(a[i] == '0'){
            ans += oneCount[b.size() - (a.size() - i - 1)] - oneCount[i];
        } else {
            ans += zeroCount[b.size() - (a.size() - i - 1)] - zeroCount[i];
        }
    }

    cout<<ans<<'\n';

}