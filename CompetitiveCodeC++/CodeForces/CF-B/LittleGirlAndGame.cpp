#include <bits/stdc++.h>
using namespace std;

int letterCount[26];
//Can rearrange if size is even and all letter counts are even
//if size is odd, and all but one letter count is odd

int main(){
    string s;
    cin >> s;
    int turnCounter = 0;

    for(char c: s){
        letterCount[c - 'a']++;
    }

    int oddOccurences = 0;
    for(int i =0; i<26; i++){
        if(letterCount[i] % 2 != 0){
            oddOccurences++;
        }
    }

    if(oddOccurences == 0 || oddOccurences % 2 != 0){
        cout<<"First";
    } else {
        cout<<"Second";
    }



    
}