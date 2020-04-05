#include <bits/stdc++.h>
using namespace std;


bool seen[26];
set<char> final[26];
set<char> otherSets[26];
set<char> newVals[26];

int main(){
    int N, currIdx;
    char a, b;

    scanf("%d", &N);
    
    for(int i = 0; i<N; i++){
        scanf(" %c %*s %c", &a, &b);
        currIdx = a - 'A';
        seen[currIdx] = true;

        if(b < 'a'){
            otherSets[currIdx].insert(b);
            seen[b -'A'] = true;

        } else {
            final[currIdx].insert(b);
        }
    }

    for(int i = 0; i<27; i++){
        for(int i = 0; i<26; i++){
            for(char c: otherSets[i]){
                newVals[i].insert(final[c-'A'].begin(), final[c-'A'].end());
            }
        }
        
        for(int i = 0; i<26; i++){
            for(char c: newVals[i]){
                final[i].insert(c);
            }
        }
    }

    for(int i = 0; i<26; i++){
        if(seen[i]){
            cout<<char(i + 'A') << " = {";
            for(auto it = final[i].begin(); it != final[i].end(); it++){
                if(++it == final[i].end()){
                    it--;
                    cout<<*it;
                } else {
                    it--;
                    cout<<*it<<",";
                }
            }
            cout<<"}"<<"\n";    
        }
        
    }

}