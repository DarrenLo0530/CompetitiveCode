#include <bits/stdc++.h>
using namespace std;
vector<char> mapping(28);

int comeBack[28];

int N;
string s;

char shuffle(int t, char c){
    for(int i = 0; i<t; i++){
        if(c >= 'A' && c <= 'Z'){
            c = mapping[c - 'A'];
        } else {
            c = mapping[26];
        }
    }
    return c;
}

int main(){
    for(int i = 0; i<=26; i++){
        cin>>mapping[i];
    }   

    cin>>N;
    cin>>s;

    string ans = "";

    for(int i = 0; i<26; i++){
        char curr = 'A' + i;
        do{
            int idx = (curr == '_') ? 26 : curr - 'A';
            comeBack[i]++;
            curr = mapping[idx];
        } while(curr != 'A' + i);
    }

    char curr = '_';
    do{
        int idx = (curr == '_') ? 26 : curr - 'A';
        comeBack[26]++;
        curr = mapping[idx];
    } while(curr != '_');


    for(int i = 0; i<s.length(); i++){
        char curr = s[i];
        int idx = (curr == '_') ? 26 : curr - 'A';
        int runTime = N % comeBack[idx];
        ans += shuffle(runTime, curr);
    }

    cout<<ans;
}
