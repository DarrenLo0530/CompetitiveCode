#include <bits/stdc++.h>
using namespace std;

int pt[1000010];
int main(){
    string s;
    int a, b;
    cin >> s >> a >> b;
    int lMod = 0;
    int rMod = 0;

    pt[0] = 1 % b;
    for(int i = 1; i<=1000010; i++){
        pt[i] = (pt[i-1] * 10) % b;
    }
    
    if(s[0] == '0'){
        printf("NO\n");
        return 0;
    }

    for(int i = 0; i<s.size(); i++){
        rMod = ((rMod * 10) % b + (s[i] - '0')) % b;
    }

    for(int i = 0; i<s.size()-1; i++){
        lMod = ((lMod * 10) % a + s[i]-'0') % a;
        rMod = ((rMod - (pt[s.size() - i - 1] * (s[i] - '0')) % b) + b) % b;
        if(s[i+1] != '0'){
            if(lMod == 0 && rMod == 0){
                printf("YES\n");
                cout<<s.substr(0, i+1)<<'\n';
                cout<<s.substr(i+1)<<'\n';
                return 0;
            }        
        }
    }

    printf("NO\n");
}