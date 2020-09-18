#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    char minChar = '}';
    for(int i = 0; i<s.size(); i++){

        if(i == 0){
            printf("Mike\n");
        } else {
            if(s[i] > minChar){
                printf("Ann\n");
            } else {
                printf("Mike\n");
            }
        }
        if(s[i] < minChar){
            minChar = s[i];
        }
    }
    
}