#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    
    char c;
    vector<char> word;
    for(int i = 0; i<n; i++){
        scanf(" %c", &c);
        word.push_back(c);
    }

    sort(word.begin(), word.end());
    for(char x: word){
        printf("%c", x);
    }
    cout<<"\n";



}