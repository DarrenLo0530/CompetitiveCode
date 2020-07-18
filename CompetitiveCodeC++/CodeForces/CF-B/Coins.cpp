#include <bits/stdc++.h>
using namespace std;

int coins[3];
int main(){
    for(int i = 0; i<3; i++){
        string s;
        cin >> s;

        int letter1 = s.at(0) - 'A';
        int letter2 = s.at(2) - 'A';
        char o = s.at(1);
        if(o == '>'){
            coins[letter1]++;
        } else {
            coins[letter2]++;
        }
    }   

    if(coins[0] && coins[1] && coins [2]){
        cout << "Impossible\n";
        return 0;
    } 

    for(int c = 0; c<=2; c++){
        for(int i = 0; i<3; i++){
            if(coins[i] == c){
                cout << (char) (i + 'A');
            }
        }
    }
    


}