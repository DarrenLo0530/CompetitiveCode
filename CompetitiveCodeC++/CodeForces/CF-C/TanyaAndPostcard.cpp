#include <bits/stdc++.h>
using namespace std;
int sl[2][26];
int tl[2][26];

int main(){
    string s;
    cin >> s;

    string t;
    cin >> t;  

    int yayCount = 0, whoopsCount = 0;

    for(char i: s){
        if(i - 'a' >= 0 && i - 'a' < 26){
            sl[0][i - 'a']++;
        } else {
            sl[1][i - 'A']++;
        }
    }

    for(char i: t){
        if(i - 'a' >= 0 && i - 'a' < 26){
            tl[0][i - 'a']++;
        } else {
            tl[1][i - 'A']++;
        }
    }

    for(int i = 0; i<26; i++){
        int diff1 = min(sl[0][i], tl[0][i]);
        yayCount += diff1;
        sl[0][i] -= diff1;
        tl[0][i] -= diff1;

        int diff2 = min(sl[1][i], tl[1][i]);
        yayCount += diff2;
        tl[1][i] -= diff2;
        sl[1][i] -= diff2;
    }

    for(int i = 0; i<26; i++){
        whoopsCount += min(sl[0][i], tl[1][i]);
        whoopsCount += min(sl[1][i], tl[0][i]);
    }

    printf("%d %d\n", yayCount, whoopsCount);

     
}