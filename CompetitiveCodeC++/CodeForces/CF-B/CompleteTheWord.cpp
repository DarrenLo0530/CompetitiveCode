#include <bits/stdc++.h>
using namespace std;

bool seen[26];
int numQuestionMarks[50001];

int main(){
    string s;
    cin >> s;
    set<char> unique;


    int l = -1, r = -1;
    for(int i = 0; i<=(int)s.size()-26; i++){
        int numQuestionMarks = 0;
        unique.clear();
        string sub = s.substr(i, 26);
        for(char c: sub){
            if(c == '?'){
                numQuestionMarks++;
            } else {
                unique.insert(c);
            }
        }

        if(unique.size() + numQuestionMarks == 26){
            l = i;
            r = i + 25;
            break;
        }
    }

    if(l == -1){
        printf("-1\n");
    } else {
        for(int i = 0; i<s.size(); i++){
            if(i >= l && i <= r){
                if(s[i] == '?'){
                    for(int i = 0; i<26; i++){
                        if(!unique.count(i + 'A')){
                            unique.insert(i + 'A');
                            printf("%c", i + 'A');
                            break;
                        }
                    }
                } else {
                    printf("%c", s[i]);
                }
            } else {
                if(s[i] == '?'){
                    printf("A");
                } else {
                    printf("%c", s[i]);
                }
            }
        }
    }




}