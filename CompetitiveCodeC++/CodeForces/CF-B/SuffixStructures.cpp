#include <bits/stdc++.h>
using namespace std;

int la[26], lb[26];

int main(){
    string a, b;
    cin >> a >> b;
    for(char i: a){
        la[i - 'a']++;
    }

    for(char i: b){
        lb[i-'a']++;
    }

    if(a.size() > b.size()){
        int aCounter = 0, bCounter = 0;
        while(bCounter < b.size() && aCounter < a.size()){
            if(a[aCounter] == b[bCounter]){
                aCounter++;
                bCounter++;
            } else {
                aCounter++;
            }
        }

        if(bCounter == b.size()){
            printf("automaton\n");
            return 0;
        }

        bool both = true;
        for(int i = 0; i<26; i++){
            if(la[i] < lb[i]){
                both = false;
            }
        }

        if(both){
            printf("both\n");
        } else {
            printf("need tree\n");
        }
    } else if (a.size() == b.size()){
        bool same = true;
        for(int i = 0; i<26; i++){
            if(la[i] != lb[i]){
                same = false;
            }
        }

        if(same){
            printf("array\n");
        } else {
            printf("need tree\n");
        }
        
    } else {
        printf("need tree\n");
    }
}